BIN_LAUNCHER=build/bdlauncher
DLL_PRELOAD=build/preload.so
MOD_LIST=$(filter-out DEPRECATED mod,$(patsubst mod/%,%,$(shell find mod -maxdepth 1 -type d -print)))
MOD_OUTS=$(patsubst %,build/mods/%.mod,$(MOD_LIST))
CFG_FILES=$(patsubst config/%.json,%,$(wildcard config/*.json))
GEN_COMMAND_SRC=$(shell find mod -regex '.*\.command\.\(h\)' -type f -print)
GEN_COMMAND_TGT=$(patsubst %.h,%.gen.cpp,$(GEN_COMMAND_SRC))
DESTDIR=/opt/bdlauncher
INSTALL_SH=./scripts/install.sh
GENERATE_COMMAND=./scripts/generate_command_definition.py
CLANG_FORMAT=clang-format

HEADERS=$(shell find include -type f -print)

LANG=CN
BDLTAG=$(shell cat version)
CFLAGS= -Os
CFLAGS+= -fPIC -std=gnu17 -DLANG=$(LANG) -DBDL_TAG=\"$(BDLTAG)\"
CXXFLAGS+= -fPIC -std=gnu++17 -DLANG=$(LANG) -DBDL_TAG=\"$(BDLTAG)\"

ifeq (1,$(RELEASE))
	OBJ_SUFFIX=release
	CFLAGS+= -s -O3 -Wall -Werror
	CXXFLAGS+= -s -O3 -Wno-invalid-offsetof
else
	OBJ_SUFFIX=debug
	CFLAGS+= -g -DDEBUG -O0 -Wall -Werror
	CXXFLAGS+= -g -DDEBUG -O0 -fsanitize=undefined -Wall -Werror -Wno-invalid-offsetof -Wno-unknown-warning-option -Wno-parentheses
	LDFLAGS+= -fsanitize=undefined
endif

.SECONDARY: obj/%.d

# Macros
define makearchive
	@echo " AR  $(1)"
	@$(AR) $(ARFLAGS) $(1) $(2)
endef
define compile
	@echo " CXX $(1)"
	@$(CXX) $(CXXFLAGS) -c -o $(1) $(2)
endef
define compilec
	@echo " CC  $(1)"
	@$(CC) $(CFLAGS) -c -o $(1) $(2)
endef
define link
	@echo " LD  $(1)"
	@$(CXX) $(LDFLAGS) $(2) -o $(1) $(3)
endef
define makedep
	@echo " DEP $1"
	@set -e; rm -f $1; $(CC) -MM $2 $(INCLUDEFLAGS) >$1.$$$$; \
		sed 's,\($*\)\.o[ :]*,$(patsubst %.d,%.o,$1) $1 : ,g' < $1.$$$$ >$1; \
    	rm -f $1.$$$$
endef
define install-trim
	$(INSTALL_SH) "$2" "$(DESTDIR)/$(patsubst $1/%,%,$2)"
endef
define install
	$(INSTALL_SH) "$1" "$(DESTDIR)/$1"
endef

# Phony Targets

.PHONY: all
all: bdlauncher preload generate-commands mods
	@echo " DONE"

.PHONY: bdlauncher preload generate-commands mods
bdlauncher: $(BIN_LAUNCHER)
preload: $(DLL_PRELOAD)
generate-commands: $(GEN_COMMAND_TGT)
mods: generate-commands $(MOD_OUTS)

.PHONY: list-mod
list-mod:
	@echo $(MOD_LIST)

.PHONY: clean
clean:
	@rm -rf obj/*.o obj/*.d
	@rm -rf $(BIN_LAUNCHER) $(DLL_PRELOAD) $(MOD_OUTS)

.PHONY: install
install: $(addprefix install-,launcher preload $(addprefix mod-,$(MOD_LIST)) $(addprefix config-,$(CFG_FILES)))
	@echo " DONE"

FORMAT_SRCS=$(patsubst ./%,%,$(shell find . -regex '.*\.\(cpp\|hpp\|cc\|cxx\|c\|h\)' -and -not -path "./include/*" -and -not -path '*/\.*')) $(shell find include/minecraft -regex '.*\.\(cpp\|hpp\|cc\|cxx\|c\|h\)') $(wildcard include/*.h include/*.hpp)
.PHONY: format
format: $(addprefix format-,$(FORMAT_SRCS))
	@echo " DONE"

.PHONY: format-%
$(addprefix format-,$(FORMAT_SRCS)): format-%: %
	@echo " FORMAT $<"
	@$(CLANG_FORMAT) -i $<

.PHONY: help
help:
	@echo available target:
	@echo common target: all clean install help format
	@echo group target: bdlauncher preload mods
	@echo mods target: $(addprefix mod-,$(MOD_LIST))

# Install Target

.PHONY: install-launcher
install-launcher: $(BIN_LAUNCHER)
	@FORCE=1 $(call install-trim,build,$<)

.PHONY: install-preload
install-preload: $(DLL_PRELOAD)
	@FORCE=1 $(call install-trim,build,$<)

.PHONY: $(addprefix install-mod-,$(MOD_LIST))
$(addprefix install-mod-,$(MOD_LIST)): install-mod-%: build/mods/%.mod
	@FORCE=1 $(call install-trim,build,$<)

.PHONY: $(addprefix install-config-,$(CFG_FILES))
$(addprefix install-config-,$(CFG_FILES)): install-config-%: config/%.json
	@$(call install,$<)

#.PHONY: install-modlist
#install-modlist: mod.list
#	@$(INSTALL_SH) mod.list "$(DESTDIR)/mods/mod.list"

# Direct Target

_BIN_LAUNCHER_SRC=$(wildcard launcher/*.c)
_BIN_LAUNCHER_OBJ=$(patsubst launcher/%.c,obj/launcher_%_$(OBJ_SUFFIX).o,$(_BIN_LAUNCHER_SRC))
_BIN_LAUNCHER_LIB=-lreadline -lutil

$(BIN_LAUNCHER): $(_BIN_LAUNCHER_OBJ) $(_BIN_LAUNCHER_LIB)
	$(call link,$@,,$^)

_DLL_PRELOAD_SRC=$(wildcard preload/*.cpp)
_DLL_PRELOAD_OBJ=$(patsubst preload/%.cpp,obj/preload_%_$(OBJ_SUFFIX).o,$(_DLL_PRELOAD_SRC))
_DLL_PRELOAD_LIB=lib/libPFishHook.a

$(DLL_PRELOAD): $(_DLL_PRELOAD_OBJ) $(_DLL_PRELOAD_LIB)
	$(call link,$@,-shared -fPIC -ldl,$^)

# Object Target

obj/launcher_%_$(OBJ_SUFFIX).o: launcher/%.c obj/launcher_%_$(OBJ_SUFFIX).d
	$(call compilec,$@,$< -Wall -Werror)
.PRECIOUS: obj/launcher_%_$(OBJ_SUFFIX).d
obj/launcher_%_$(OBJ_SUFFIX).d: launcher/%.c
	$(call makedep,$@,$<)

obj/preload_%_$(OBJ_SUFFIX).o: preload/%.cpp obj/preload_%_$(OBJ_SUFFIX).d
	$(call compile,$@,$< -I include)
.PRECIOUS: obj/preload_%_$(OBJ_SUFFIX).d
obj/preload_%_$(OBJ_SUFFIX).d: preload/%.cpp
	$(call makedep,$@,$< -I include)

# Mod Target

.DELETE_ON_ERROR:
$(GEN_COMMAND_TGT) : %.gen.cpp: %.h $(GENERATE_COMMAND)
	@echo " GENERATE $@"
	@$(GENERATE_COMMAND) $< | $(CLANG_FORMAT) >$@

define build-mods-rules
MOD_$1=build/mods/$1.mod
_MOD_$1_SRC=$$(wildcard mod/$1/*.cpp)
_MOD_$1_OBJ=$$(patsubst mod/$1/%.cpp,obj/mod_$1_%_$(OBJ_SUFFIX).o,$$(_MOD_$1_SRC))

.PHONY: MOD_$1
mod-$1: $$(MOD_$1)

$$(MOD_$1): $$(_MOD_$1_OBJ)
	$(call link,$$@,-shared -fPIC -ldl -fvisibility=hidden,$$^)

obj/mod_$1_%_$$(OBJ_SUFFIX).o: mod/$1/%.cpp obj/mod_$1_%_$(OBJ_SUFFIX).d
	$(call compile,$$@,$$< -I include -I mod/base -fvisibility=hidden -DMOD_NAME=\"$1\")

.PRECIOUS: obj/mod_$1_%_$$(OBJ_SUFFIX).d
obj/mod_$1_%_$$(OBJ_SUFFIX).d: mod/$1/%.cpp
	$(call makedep,$$@,$$< -I include -I mod/base -fvisibility=hidden -DMOD_NAME=\"$1\")
endef

$(foreach mod,$(MOD_LIST),$(eval $(call build-mods-rules,$(mod))))

$(MOD_base): lib/libleveldb.a
-include obj/*.d
