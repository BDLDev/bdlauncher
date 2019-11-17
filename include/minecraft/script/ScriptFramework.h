#pragma once

#include <string>
#include <vector>

#ifndef PATCHABLE
#define PATCHABLE
#endif

namespace ScriptApi {

class ScriptReport;
class ScriptCallbackInterface;
class ScriptObjectHandle;
enum class ScriptObjectType;

class ScriptFramework {
  char filler[0x30];

public:
  bool initialize();
  bool registerGlobalAPI(std::string const &name, ScriptCallbackInterface &, ScriptObjectHandle &);
  ScriptReport &getScriptReportQueue() const;

  bool runScript(std::string const &, std::string const &);
  bool createObject(ScriptObjectHandle &);
  bool createArray(ScriptObjectHandle &, int const &);
  bool cloneObject(ScriptObjectHandle const &, ScriptObjectHandle &);
  bool hasMember(ScriptObjectHandle const &, std::string const &, bool &);
  bool hasMember(ScriptObjectHandle const &, int const &, bool &);
  bool setMember(ScriptObjectHandle const &, std::string const &, ScriptObjectHandle const &);
  bool setMember(ScriptObjectHandle const &handle, std::string const &name, bool value) PATCHABLE;
  bool setMember(ScriptObjectHandle const &handle, std::string const &name, double value) PATCHABLE;
  bool setMember(ScriptObjectHandle const &handle, std::string const &name, int value) PATCHABLE;
  bool setMember(ScriptObjectHandle const &handle, std::string const &name, long value) PATCHABLE;
  bool setMember(ScriptObjectHandle const &handle, std::string const &name, std::string const &value) PATCHABLE;
  bool setMember(ScriptObjectHandle const &, int const &, ScriptObjectHandle const &);
  bool getMember(ScriptObjectHandle const &, std::string const &, ScriptObjectHandle &);
  bool getMember(ScriptObjectHandle const &handle, std::string const &name, bool &value) PATCHABLE;
  bool getMember(ScriptObjectHandle const &handle, std::string const &name, double &value) PATCHABLE;
  bool getMember(ScriptObjectHandle const &handle, std::string const &name, int &value) PATCHABLE;
  bool getMember(ScriptObjectHandle const &handle, std::string const &name, long &value) PATCHABLE;
  bool getMember(ScriptObjectHandle const &handle, std::string const &name, std::string &value) PATCHABLE;
  bool getMember(ScriptObjectHandle const &, int const &, ScriptObjectHandle &);
  bool setValue(ScriptObjectHandle &, int);
  bool setValue(ScriptObjectHandle &, double);
  bool setValue(ScriptObjectHandle &, long);
  bool setValue(ScriptObjectHandle &, std::string const &);
  bool setValue(ScriptObjectHandle &, bool);
  bool getValue(ScriptObjectHandle const &, int &);
  bool getValue(ScriptObjectHandle const &, double &);
  bool getValue(ScriptObjectHandle const &, long &);
  bool getValue(ScriptObjectHandle const &, std::string &);
  bool getValue(ScriptObjectHandle const &, bool &);
  bool callObjectFunction(ScriptObjectHandle const &, std::string const &, std::vector<ScriptObjectHandle> const &, ScriptObjectHandle &);
  bool callGlobalFunction(ScriptObjectHandle const &, std::vector<ScriptObjectHandle> const &, ScriptObjectHandle &);
  bool getHandleType(ScriptObjectHandle const &, ScriptObjectType &);
  bool getMemberNames(ScriptObjectHandle const &, std::vector<std::string> &);
  bool getArrayLength(ScriptObjectHandle const &, int &);
  bool getGlobalObject(ScriptObjectHandle &);
  bool createUndefined(ScriptObjectHandle &);
  bool createNull(ScriptObjectHandle &);
};
} // namespace ScriptApi