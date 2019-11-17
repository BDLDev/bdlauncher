#pragma once

#include <memory>
#include <unordered_map>

class ScriptServerContext;
class ScriptEngine;
class Actor;
class Level;
class Block;
class BlockSource;
struct BlockPos;

#ifndef PATCHABLE
#define PATCHABLE
#endif

namespace ScriptApi {
struct ScriptVersionInfo;
class ScriptObjectHandle;
} // namespace ScriptApi

template <typename T = ScriptServerContext> class ScriptTemplateFactory;

template <> class ScriptTemplateFactory<ScriptServerContext> {
public:
  template <typename T> class Entries {
  public:
    std::unordered_map<std::string, std::shared_ptr<T>> data;

    template <typename F> void add();
    std::weak_ptr<T> get(std::string const &) const;
  };

  class Entity {
  public:
    bool createAndApplyTemplate(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, ScriptApi::ScriptObjectHandle &,
                                std::string const &) const;

    virtual ~Entity();
    virtual bool createAndApplyTemplate(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Actor **,
                                        std::string const &) const;
  };
  class Component {
  public:
    bool applyComponentTo(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, ScriptApi::ScriptObjectHandle const &,
                          ScriptApi::ScriptObjectHandle const &) const PATCHABLE;
    bool retrieveComponentFrom(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, ScriptApi::ScriptObjectHandle const &,
                               ScriptApi::ScriptObjectHandle &) const PATCHABLE;
    bool hasComponent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, ScriptApi::ScriptObjectHandle const &,
                      bool &) const PATCHABLE;

    virtual ~Component();
    virtual bool applyComponentTo(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Actor &,
                                  ScriptApi::ScriptObjectHandle const &) const;
    virtual bool retrieveComponentFrom(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Actor &,
                                       ScriptApi::ScriptObjectHandle &) const;
    virtual bool hasComponent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Actor &, bool &) const = 0;
    virtual bool applyComponentTo(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Level &,
                                  ScriptApi::ScriptObjectHandle const &) const;
    virtual bool retrieveComponentFrom(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Level &,
                                       ScriptApi::ScriptObjectHandle &) const;
    virtual bool hasComponent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Level &, bool &) const;
    virtual bool applyComponentTo(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Block const &, BlockSource &,
                                  BlockPos &, ScriptApi::ScriptObjectHandle const &) const;
    virtual bool retrieveComponentFrom(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Block const &,
                                       ScriptApi::ScriptObjectHandle &) const;
    virtual bool hasComponent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, Block const &, bool &) const;
  };
  class ReceivedEvent {
  public:
    virtual ~ReceivedEvent();
    virtual bool receivedEvent(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                               ScriptApi::ScriptObjectHandle const &) = 0;
    virtual bool getEventData(ScriptApi::ScriptVersionInfo const &, ScriptEngine &, ScriptServerContext &, std::string const &,
                              ScriptApi::ScriptObjectHandle &)        = 0;
  };

  Entries<Entity> majorEntities, minorEntities;
  Entries<Component> components;
  Entries<ReceivedEvent> events;
  std::shared_ptr<ReceivedEvent> custtom_event;
};