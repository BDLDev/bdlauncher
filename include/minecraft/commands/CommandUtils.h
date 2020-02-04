#pragma once

class BlockSource;
class Vec3;
class ActorDefinitionIdentifier;
struct ActorUniqueID;
class Actor;

class CommandUtils {
public:
  static void spawnEntityAt(BlockSource &, Vec3 const &, ActorDefinitionIdentifier const &, ActorUniqueID &, Actor *unk = nullptr);
};