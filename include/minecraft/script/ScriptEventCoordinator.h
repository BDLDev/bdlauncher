#pragma once

#include "../event/EventCoordinator.h"

class ScriptEventListener;

enum class RegistrationType;

class ScriptEventCoordinator : public EventCoordinator<ScriptEventListener> {
public:
  void sendScriptAddFilterToView(std::string const &);
  void sendScriptBroadcastEvent(std::string const &, RegistrationType, bool);
  void sendScriptError(std::string const &, std::string const &);
  void sendScriptGetComponent(std::string const &, RegistrationType, bool);
  void sendScriptInternalError(std::string const &);
  void sendScriptListenForEvent(std::string const &);
  void sendScriptLoaded(std::string const &, unsigned long);
  void sendScriptRan(std::string const &, std::string const &, bool);
  void sendScriptRegisterSpatialView(std::string const&);
  void sendScriptRegisterView();
};