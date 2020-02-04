#pragma once
#include <string>
#include <memory>

#include "minecraft/json.h"
#include "minecraft/block/BlockPos.h"

class CompoundTag;
class ContentIdentity;
class GameRules;
class GameType;
typedef int Difficulty;
class ContentIdentity;

class LevelData{
public:
	char fill[1184];

void getTagData(CompoundTag const&);
void setGameType(GameType);
void setRainTime(int);
void setSpawnPos(BlockPos const&);
GameRules* getGameRules();;
//void setGenerator(GeneratorType);
void setLevelName(std::string const&);
void setRainLevel(float);
void setSpawnMobs(bool);
void incrementTick();
//0000000007cb4890 T LevelData::recordStartUp()
//void setCurrentTick(Tick&);
void setEducationOid(std::string const&);
void setLANBroadcast(bool);
void setForceGameType(bool);
void setLightningTime(int);
void setGameDifficulty(Difficulty);
void setLightningLevel(float);
void setNetworkVersion(int);
//void setStorageVersion(StorageVersion);
CompoundTag getLoadedPlayerTag();
//void setBaseGameVersion(BaseGameVersion const&);
void setCommandsEnabled(bool);
void setMultiplayerGame(bool);
bool disableAchievements();
//0000000007cb4c20 T LevelData::getDefaultAbilities()
//void setXBLBroadcastMode(Social::GamePublishSetting)
//0000000007cb4300 T LevelData::clearLoadedPlayerTag()
//0000000007cb4bd0 T LevelData::getAdventureSettings()
void setBonusChestEnabled(bool);
void setBonusChestSpawned(bool);
void setFromWorldTemplate(bool);
void setEducationProductId(std::string const&);
void setFromLockedTemplate(bool);
void setLANBroadcastIntent(bool);
//void setXBLBroadcastIntent(Social::GamePublishSetting);
void setStartWithMapEnabled(bool);
void setUseMsaGamertagsOnly(bool);
void setOnlySpawnV1Villagers(bool);
void setServerChunkTickRange(unsigned int);
void setTexturepacksRequired(bool);
//void setEducationEditionOffer(EducationEditionOffer);
void setHasLockedBehaviorPack(bool);
void setHasLockedResourcePack(bool);
void setMultiplayerGameIntent(bool);
//void setPlatformBroadcastMode(Social::GamePublishSetting);
//void setWorldTemplateIdentity(PackIdVersion const&);
void _updateLimitedWorldOrigin(BlockPos const&);
//void setPlatformBroadcastIntent(Social::GamePublishSetting);
void touchLastLoadedWithVersion();
void setEducationFeaturesEnabled(bool);
void setWorldTemplateOptionLocked(bool);
void setConfirmedPlatformLockedContent(bool);
void setPremiumTemplateContentIdentity(ContentIdentity const&);
void setRequiresCopiedPackRemovalCheck(bool);
bool _setGameRulesBasedOnPremiumContentIdentity();
void setSeed(unsigned int);
void setTime(int);
//void v1_read(RakNet::BitStream&, StorageVersion);
//bool isGameRule(GameRuleId) const;
bool isNewLevel() const;
void setTagData(CompoundTag&) const;
unsigned int getGameType() const;
int getRainTime() const;
BlockPos getSpawnPos() const;
bool hasSpawnPos() const;
bool isAlwaysDay() const;
bool isLightning() const;
std::string& getLevelName() const;
float getRainLevel() const;
int getLightningTime() const;
float getLightningLevel() const;
/*
0000000007cb4160 T LevelData::getGameRules() const
0000000007cb4400 T LevelData::getGenerator() const
0000000007cb4730 T LevelData::getSpawnMobs() const
0000000007cb44d0 T LevelData::getLastPlayed() const
0000000007cb54d0 T LevelData::isLegacyLevel() const
0000000007cb4b40 T LevelData::getCurrentTick() const
0000000007cb54b0 T LevelData::getNetherScale() const
0000000007cb48d0 T LevelData::getWorldCenter() const
0000000007cb5290 T LevelData::getEducationOid[abi:cxx11]() const
0000000007cb4e10 T LevelData::getLANBroadcast() const
0000000007cb46e0 T LevelData::getForceGameType() const
0000000007cb46a0 T LevelData::getGameDifficulty() const
0000000007cb4970 T LevelData::getNetworkVersion() const
0000000007cb4910 T LevelData::getStorageVersion() const
0000000007cb4d70 T LevelData::isMultiplayerGame() const
0000000007cb4aa0 T LevelData::getBaseGameVersion() const
0000000007cb48f0 T LevelData::getWorldStartCount() const
0000000007cb4870 T LevelData::hasCommandsEnabled() const
0000000007cb4c00 T LevelData::getDefaultAbilities() const
0000000007cb4ea0 T LevelData::getXBLBroadcastMode() const
0000000007cb51b0 T LevelData::isFromWorldTemplate() const
0000000007cb5370 T LevelData::getBonusChestSpawned() const
0000000007cb5350 T LevelData::hasBonusChestEnabled() const
0000000007cb5140 T LevelData::isFromLockedTemplate() const
0000000007cb44f0 T LevelData::updateLastTimePlayed() const
0000000007cb52f0 T LevelData::getEducationProductId[abi:cxx11]() const
0000000007cb4dc0 T LevelData::getLANBroadcastIntent() const
0000000007cb4e60 T LevelData::getXBLBroadcastIntent() const
0000000007cb5060 T LevelData::hasLockedBehaviorPack() const
0000000007cb50d0 T LevelData::hasLockedResourcePack() const
bool getUseMsaGamertagsOnly() const;
0000000007cb53f0 T LevelData::hasStartWithMapEnabled() const
0000000007cb49b0 T LevelData::isPremiumWorldTemplate() const
0000000007cb5010 T LevelData::isTexturepacksRequired() const
0000000007cb5490 T LevelData::getOnlySpawnV1Villagers() const
0000000007cb4200 T LevelData::getServerChunkTickRange() const
0000000007cb4780 T LevelData::hasAchievementsDisabled() const
0000000007cb5440 T LevelData::hasMapsCenteredToOrigin() const
bool isEducationEditionLevel() const;
0000000007cb4c80 T LevelData::educationFeaturesEnabled() const
0000000007cb4c40 T LevelData::getEducationEditionOffer() const
000000000731c7e0 W LevelData::getLastLoadedWithVersion() const
0000000007cb4d20 T LevelData::getMultiplayerGameIntent() const
0000000007cb4f20 T LevelData::getPlatformBroadcastMode() const
0000000007cb4a40 T LevelData::getWorldTemplateIdentity() const
0000000007cb4ee0 T LevelData::getPlatformBroadcastIntent() const
0000000007cb5210 T LevelData::isWorldTemplateOptionLocked() const
*/
CompoundTag getFlatWorldGeneratorOptions() const;
//0000000007cb4950 T LevelData::getMinCompatibleClientVersion() const
bool hasExperimentalGameplayEnabled() const;
bool requiresCopiedPackRemovalCheck() const;
bool achievementsWillBeDisabledOnLoad() const;
//ContentIdentity* getPremiumTemplateContentIdentity() const;
//0000000007cb4cd0 T LevelData::hasConfirmedPlatformLockedContent() const
unsigned int getSeed() const;
int getTime() const;
CompoundTag createTag() const;
bool isRaining() const;

//operator=(LevelData&&);

};
