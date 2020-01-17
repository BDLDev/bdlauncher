#!/usr/bin/env python3
import cppheaderparser
import sys
import os
import re
from typing import List


def debug(data):
    print(data, file=sys.stderr)


class DynEnum:
    """Custom Dynamic Enum"""

    def __init__(self, name: str):
        self.name = name

    def __str__(self) -> str:
        return " FOUND %s" % (self.name)

    def generate_clazz(self):
        print("template <> class BDL::CustomCommand::CommandParameterProxy<%s>" % self.name)
        print("\t: public CommandParameterProxy<std::string> {")
        print("public:")
        print(
            "\tinline static constexpr auto type = CommandParameterDataType::SOFT_ENUM;"
        )
        print("")
        print("\toperator %s() const noexcept { return {value}; }" % self.name)
        print("};")
        print("")

    def generate_application(self):
        print("\tinstance.registerDynEnum<%s>();" % self.name)

    @staticmethod
    def scan(header: cppheaderparser.CppHeader):
        return [
            DynEnum(name)
            for name, clazz in header.classes.items()
            if any(
                inherit
                for inherit in clazz["inherits"]
                if inherit["class"] == "CustomDynEnum<%s>" % name
            )
        ]


class Enum:
    """Custom Enum"""

    def __init__(self, name: str, dic: list):
        self.name = name
        self.values = [str(item["name"]) for item in dic]

    def __str__(self) -> str:
        return " FOUND %s = %s" % (self.name, str(self.values))

    def generate_clazz(self):
        print("template <> class BDL::CustomCommand::CommandParameterProxy<%s> {" % self.name)
        print("\t%s value;" % self.name)
        print("")
        print("public:")
        print(
            "static auto fetch_tid() { return type_id<CommandRegistry, %s>(); }"
            % self.name
        )
        print("static constexpr auto parser = &CommandRegistry::fake_parse;")
        print("static constexpr auto type = CommandParameterDataType::NORMAL;")
        print('static constexpr auto enum_name = "%s";' % self.name)
        print("")
        print("operator %s() const noexcept { return value; }" % self.name)
        print("};")
        print("")

    def generate_application(self):
        print("\t{")
        print("\t\tauto &item = instance.registerEnum<%s>();" % self.name)
        for value in self.values:
            print(
                '\t\titem.addValue("%s", %s::%s);' % (value.lower(), self.name, value)
            )
        print("\t}")

    @staticmethod
    def scan(header: cppheaderparser.CppHeader):
        return [Enum(item["name"], item["values"]) for item in header.enums]


class CommandDefinition:
    """Custom Command Definition, should extends CustomCommandContext"""

    class OverloadDefinition:
        """Custom Command Overload Definition, generated from public method"""

        class ParameterDefinition:
            """Custom Command Overload Parameter Definition, generated from method parameter"""

            def __init__(self, name: str, stype: str):
                self.name = name
                m = re.search("^(optional|mandatory)<(.+?)>$", stype)
                optional = False
                if m:
                    stype = m.group(2)
                    optional = m.group(1) == "optional"
                self.type = stype
                self.optional = optional
                pass

            def __str__(self) -> str:
                return ("[%s: %s]" if self.optional else "<%s: %s>") % (
                    self.name,
                    self.type,
                )

        def __init__(self, name: str, dic: list):
            self.name = name
            self.parameters = [
                CommandDefinition.OverloadDefinition.ParameterDefinition(
                    param["name"], param["type"]
                )
                for param in dic
            ]
            pass

        def __str__(self) -> str:
            return self.name + " " + " ".join(str(item) for item in self.parameters)

        def generate_clazz(self, clazz_name: str, idx: int):
            print("struct %s_%d : Command {" % (clazz_name, idx))
            for param in self.parameters:
                print("\tCommandParameterProxy<%s> %s;" % (param.type, param.name))
            print(
                "\tvirtual void execute(CommandOrigin const &origin, CommandOutput &output) override {"
            )
            print("\t\t%s context {origin, output};" % clazz_name)
            print(
                "\t\tcontext.%s(%s);"
                % (self.name, ", ".join(param.name for param in self.parameters))
            )
            print("\t}")
            print("};")
            print("")

        def generate_application(self, clazz_name: str, idx: int):
            ovltype="%s_%d"% (clazz_name, idx)
            print("\t\t{")
            print(
                "\t\t\tauto &ovl = cmd.registerOverload<%s>();" % ovltype
            )
            for param in self.parameters:
                optional = "true" if param.optional else "false"
                print(
                    '\t\t\tovl.addParameter<{type}>("{name}", {optional}, offsetof({ovltype}, {name}));'.format(
                        type=param.type, optional=optional, name=param.name, ovltype=ovltype
                    )
                )
            print("\t\t}")

    def __init__(self, name: str, dic: dict):
        self.name = name
        self.overloads = [
            CommandDefinition.OverloadDefinition(method["name"], method["parameters"])
            for method in dic
            if not method["static"] and not method["constructor"]
        ]

    def __str__(self) -> str:
        return (
            " FOUND "
            + self.name
            + "\n\t"
            + "\n\t".join(str(item) for item in self.overloads)
        )

    def generate_clazz(self):
        for idx, overload in enumerate(self.overloads):
            overload.generate_clazz(self.name, idx)

    def generate_application(self):
        print("\t{")
        print("\t\tauto &cmd = instance.registerCommand<%s>();" % self.name)
        for idx, overload in enumerate(self.overloads):
            overload.generate_application(self.name, idx)
        print("\t}")

    @staticmethod
    def scan(header: cppheaderparser.CppHeader):
        return [
            CommandDefinition(name, clazz["methods"]["public"])
            for name, clazz in header.classes.items()
            if any(
                inherit
                for inherit in clazz["inherits"]
                if inherit["class"] == "CustomCommandContext"
            )
        ]


if len(sys.argv) != 2:
    debug("%s <filename>" % sys.argv[0])
    exit(1)

filename = sys.argv[1]

try:
    basename: str = os.path.basename(filename)
    debug(" PARSE %s" % filename)
    header = cppheaderparser.CppHeader(filename)
    defined = [
        func
        for func in header.functions
        if func["returns"] == "command_register_function"
        and len(func["parameters"]) == 0
    ]
    if len(defined) != 1:
        debug("Failed to find command_register_function")
        exit(1)
    command_register_function = defined[0]["name"]
    debug(" SCAN dynamic enum")
    dynenums: List[DynEnum] = DynEnum.scan(header)
    debug("\n".join(str(item) for item in dynenums))
    debug(" SCAN enums")
    enums: List[Enum] = Enum.scan(header)
    debug("\n".join(str(item) for item in enums))
    debug(" SCAN commands")
    commands: List[CommandDefinition] = CommandDefinition.scan(header)
    debug("\n".join(str(item) for item in commands))
    debug(" GENERATE-HEADER")
    print("// Generated by scripts/generate_command_definition.py")
    print("")
    print('#include "%s"' % basename)
    print("")
    debug(" GENERATE-CLASSES")
    for item in dynenums:
        item.generate_clazz()
    for item in enums:
        item.generate_clazz()
    for item in commands:
        item.generate_clazz()
    debug(" GENERATE-APPLICATIONS")
    print("void %s() {" % command_register_function)
    print("\tauto &instance = CustomCommandRegistry::getInstance();")
    for item in dynenums:
        item.generate_application()
    for item in enums:
        item.generate_application()
    for item in commands:
        item.generate_application()
    print("}")
except cppheaderparser.CppParseError as e:
    debug(e)
    sys.exit(1)
