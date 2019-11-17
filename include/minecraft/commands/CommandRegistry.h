#pragma once

#include "../core/typeid.h"
#include "../core/types.h"
#include "CommandLexer.h"
#include "CommandVersion.h"

#include<climits>
#include <memory>
#include <vector>

class Command;
class CommandOrigin;
class CommandParameterData;
class HardNonTerminal;
enum class CommandFlag;

class CommandRegistry {
public:
  class ParseToken;
  struct Symbol {
    unsigned val;

    Symbol(unsigned long);
    Symbol();
    Symbol(Symbol const &);
    Symbol(CommandLexer::TokenType);
    Symbol(HardNonTerminal);

    static Symbol fromEnumIndex(unsigned long);
    static Symbol fromEnumValueIndex(unsigned long);
    static Symbol fromFactorizationIndex(unsigned long);
    static Symbol fromOptionalIndex(unsigned long);
    static Symbol fromPostfixIndex(unsigned long);
    static Symbol fromSoftEnumIndex(unsigned long);

    Symbol &operator=(Symbol const &);
    bool operator==(Symbol const &) const;
    bool operator!=(Symbol const &) const;
    bool operator<(Symbol const &) const;

    bool isEnum() const;
    bool isEnumValue() const;
    bool isFactorization() const;
    bool isOptional() const;
    bool isPostfix() const;
    bool isSoftEnum() const;
    bool isTerminal() const;

    unsigned toIndex() const;
    unsigned value() const;
  };
  struct Enum {
    using ParseFn = bool (CommandRegistry::*)(void *, CommandRegistry::ParseToken const &, CommandOrigin const &, int, std::string &,
                                              std::vector<std::string> &);
    std::string name;
    typeid_t<CommandRegistry> tid;
    ParseFn parseFn;
    std::vector<std::pair<unsigned long, unsigned long>> vpuu;
    Enum(std::string const &, typeid_t<CommandRegistry>, ParseFn const);
    Enum(Enum &&);
    ~Enum();
  };
  struct Overload {
    using FactoryFn = std::unique_ptr<Command> (*)(void);
    CommandVersion version;
    FactoryFn factory;
    std::vector<CommandParameterData> params;
    bool unk;
    Overload(CommandVersion, FactoryFn);
  };
  struct Signature {
    std::string name;                // 0
    std::string desc;                // 32
    std::vector<Overload> overloads; // 64
    CommandPermissionLevel perm;     // 88
    Symbol main_symbol;              // 92
    Symbol alt_symbol;               // 96
    CommandFlag flag;                // 100
    int unk104;                      // 104
    int unk108;                      // 108
    int unk112;                      // 112
    bool b116;                       // 116

    Signature(std::string const &, char const *, CommandPermissionLevel, Symbol, CommandFlag);
    Signature(Signature &&);
    ~Signature();
  };
  struct SoftEnum {
    std::string name;              // 0
    std::vector<std::string> list; // 32
    SoftEnum(std::string const &, std::vector<std::string>);
    SoftEnum(SoftEnum &&);
    SoftEnum &operator=(SoftEnum &&);
    ~SoftEnum();
  };
  template <typename Type, typename TConverter>
  bool parseEnum(void *, ParseToken const &, CommandOrigin const &, int, std::string &, std::vector<std::string> &) const {
    return true;
  }
  template <typename Type> bool parse(void *, ParseToken const &, CommandOrigin const &, int, std::string &, std::vector<std::string> &) const;

  void registerCommand(std::string const &, char const *, CommandPermissionLevel, CommandFlag, CommandFlag);
  void buildOverload(CommandRegistry::Overload &);
  void registerOverloadInternal(Signature &, Overload &);
  Signature *findCommand(std::string const &);

  template <typename F> void registerCustomOverload(std::string name, CommandVersion version, std::unique_ptr<Command> (*allocator)(), F f) {
    Signature *signature = findCommand(name);
    signature->overloads.emplace_back(version, allocator);
    Overload &overload = *signature->overloads.rbegin();
    buildOverload(overload);
    f(overload);
    registerOverloadInternal(*signature, overload);
  }
  template <typename T> static std::unique_ptr<Command> allocateCommand() { return std::unique_ptr<Command>(new T()); }
  template <typename... Args> void registerOverload2(const char *name,void* allo, Args &&... args) {
    Signature *signature = findCommand(name);
    signature->overloads.emplace_back((CommandVersion){0,INT_MAX}, (Overload::FactoryFn)allo);
    Overload &overload = *signature->overloads.rbegin();
    buildOverload(overload);
    overload.params = { args... };
    registerOverloadInternal(*signature, overload);
  }
};