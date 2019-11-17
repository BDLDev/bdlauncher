#pragma once

#include "../ScriptTemplateFactory.h"

#include <string>

#ifndef PATCHABLE
#define PATCHABLE
#endif

class ScriptServerBroadcastReceived : public ScriptTemplateFactory<ScriptServerContext>::ReceivedEvent {
public:
  ScriptServerBroadcastReceived();
  virtual ~ScriptServerBroadcastReceived() override;
  virtual bool receivedEvent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                             ScriptApi::ScriptObjectHandle const &) override;
  virtual bool getEventData(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                            ScriptApi::ScriptObjectHandle &) override;
  static std::string getName();
};

class ScriptServerChatReceived : public ScriptTemplateFactory<ScriptServerContext>::ReceivedEvent {
public:
  ScriptServerChatReceived();
  virtual ~ScriptServerChatReceived() override;
  virtual bool receivedEvent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                             ScriptApi::ScriptObjectHandle const &) override;
  virtual bool getEventData(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                            ScriptApi::ScriptObjectHandle &) override;
  static std::string getName();
};

class ScriptServerCommandReceived : public ScriptTemplateFactory<ScriptServerContext>::ReceivedEvent {
public:
  ScriptServerCommandReceived();
  virtual ~ScriptServerCommandReceived() override;
  virtual bool receivedEvent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                             ScriptApi::ScriptObjectHandle const &) override;
  virtual bool getEventData(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                            ScriptApi::ScriptObjectHandle &) override;
  static std::string getName();
};

class ScriptServerLoggerConfigReceivedEvent : public ScriptTemplateFactory<ScriptServerContext>::ReceivedEvent {
public:
  ScriptServerLoggerConfigReceivedEvent();
  virtual ~ScriptServerLoggerConfigReceivedEvent() override;
  virtual bool receivedEvent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                             ScriptApi::ScriptObjectHandle const &) override;
  virtual bool getEventData(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                            ScriptApi::ScriptObjectHandle &) override;
  static std::string getName(); // minecraft:script_logger_config
};

class ScriptServerPlaySoundEvent : public ScriptTemplateFactory<ScriptServerContext>::ReceivedEvent {
public:
  ScriptServerPlaySoundEvent();
  virtual ~ScriptServerPlaySoundEvent() override;
  virtual bool receivedEvent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                             ScriptApi::ScriptObjectHandle const &) override;
  virtual bool getEventData(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                            ScriptApi::ScriptObjectHandle &) override;
  static std::string getName();
};

class ScriptServerSpawnParticleAttachedToActor : public ScriptTemplateFactory<ScriptServerContext>::ReceivedEvent {
public:
  ScriptServerSpawnParticleAttachedToActor();
  virtual ~ScriptServerSpawnParticleAttachedToActor() override;
  virtual bool receivedEvent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                             ScriptApi::ScriptObjectHandle const &) override PATCHABLE;
  virtual bool getEventData(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                            ScriptApi::ScriptObjectHandle &) override PATCHABLE;
  static std::string getName();
};

class ScriptServerSpawnParticleInWorldEvent : public ScriptTemplateFactory<ScriptServerContext>::ReceivedEvent {
public:
  ScriptServerSpawnParticleInWorldEvent();
  virtual ~ScriptServerSpawnParticleInWorldEvent() override;
  virtual bool receivedEvent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                             ScriptApi::ScriptObjectHandle const &) override;
  virtual bool getEventData(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                            ScriptApi::ScriptObjectHandle &) override;
  static std::string getName();
};