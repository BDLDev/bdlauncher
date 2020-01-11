BIN_LAUNCHER=build/bdlauncher
DLL_PRELOAD=build/preload.so
MOD_LIST=$(filter-out DEPRECATED,$(patsubst mod/%,%,$(shell find mod -maxdepth 1 -type d -print)))
MOD_OUTS=$(patsubst %,build/mods/%.mod,$(MOD_LIST))
DESTDIR=/opt/bdlauncher

HEADERS=$(shell find include -type f -print)

LANG=CN
CFLAGS+= -fPIC -std=gnu11 -DLANG=$(LANG)
CXXFLAGS+= -fPIC -std=gnu++17 -DLANG=$(LANG)

ifeq (1,$(RELEASE))
	OBJ_SUFFIX=release
	CFLAGS+= -s -O3
	CXXFLAGS+= -s -O3
	LDFLAGS+= -Wl,-z,relro,-z,now
else
	OBJ_SUFFIX=debug
	CFLAGS+= -g -DDEBUG -O0
	CXXFLAGS+= -g -DDEBUG -O0
endif

.SECONDARY: obj/%.d

# Macros
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

# Phony Targets

.PHONY: all
all: bdlauncher preload mods
	@echo DONE!

.PHONY: bdlauncher preload mods
bdlauncher: $(BIN_LAUNCHER)
preload: $(DLL_PRELOAD)
mods: $(MOD_OUTS) build/mods/mod.list

build/mods/mod.list: mod.list
	@echo " CP  $@"
	@cp $< $@

.PHONY: list-mod
list-mod:
	@echo $(MOD_LIST)

.PHONY: clean
clean:
	@rm -rf obj/*.o obj/*.d
	@rm -rf $(BIN_LAUNCHER) $(DLL_PRELOAD) $(MOD_OUTS) build/mods/mod.list

.PHONY: install
install: all
	@cp -a build $(DESTDIR)
	@cp -a config $(DESTDIR)

# Direct Target

_BIN_LAUNCHER_SRC=$(wildcard launcher/*.c)
_BIN_LAUNCHER_OBJ=$(patsubst launcher/%.c,obj/launcher_%_$(OBJ_SUFFIX).o,$(_BIN_LAUNCHER_SRC))

$(BIN_LAUNCHER): $(_BIN_LAUNCHER_OBJ)
	$(call link,$@,,$^)

_DLL_PRELOAD_SRC=$(wildcard preload/*.cpp)
_DLL_PRELOAD_OBJ=$(patsubst preload/%.cpp,obj/preload_%_$(OBJ_SUFFIX).o,$(_DLL_PRELOAD_SRC))
_DLL_PRELOAD_LIB=lib/libPFishHook.a

$(DLL_PRELOAD): $(_DLL_PRELOAD_OBJ) $(_DLL_PRELOAD_LIB)
	$(call link,$@,-shared -fPIC -ldl,$^)

# Object Target

obj/launcher_%_$(OBJ_SUFFIX).o: launcher/%.c obj/launcher_%_$(OBJ_SUFFIX).d
	$(call compilec,$@,$<)
.PRECIOUS: obj/launcher_%_$(OBJ_SUFFIX).d
obj/launcher_%_$(OBJ_SUFFIX).d: launcher/%.c
	$(call makedep,$@,$<)

obj/preload_%_$(OBJ_SUFFIX).o: preload/%.cpp obj/preload_%_$(OBJ_SUFFIX).d
	$(call compile,$@,$< -I include)
.PRECIOUS: obj/preload_%_$(OBJ_SUFFIX).d
obj/preload_%_$(OBJ_SUFFIX).d: preload/%.cpp
	$(call makedep,$@,$< -I include)

# Mod Target

define build-mods-rules
MOD_$1=build/mods/$1.mod
_MOD_$1_SRC=$$(wildcard mod/$1/*.cpp)
_MOD_$1_OBJ=$$(patsubst mod/$1/%.cpp,obj/mod_$1_%_$(OBJ_SUFFIX).o,$$(_MOD_$1_SRC))

.PHONY: MOD_$1
mod-$1: $$(MOD_$1)

$$(MOD_$1): $$(_MOD_$1_OBJ)
	$(call link,$$@,-shared -fPIC -ldl -fvisibility=hidden,$$^)

obj/mod_$1_%_$$(OBJ_SUFFIX).o: mod/$1/%.cpp obj/mod_$1_%_$(OBJ_SUFFIX).d
	$(call compile,$$@,$$< -I include -I mod/base -fvisibility=hidden)

.PRECIOUS: obj/mod_$1_%_$$(OBJ_SUFFIX).d
obj/mod_$1_%_$$(OBJ_SUFFIX).d: mod/$1/%.cpp
	$(call makedep,$$@,$$< -I include -I mod/base -fvisibility=hidden)
endef

$(foreach mod,$(MOD_LIST),$(eval $(call build-mods-rules,$(mod))))

$(MOD_base): lib/libleveldb.a
-include obj/*.d