#pragma once
#include <string>

enum class GameType { Survival = 0, Creative = 1, Adventure = 2, Default = 5, Unknown = -1 };

namespace GameTypeConv {
std::string gameTypeToNonLocString(GameType);
std::string gameTypeToString(GameType);
GameType intToGameType(int);
GameType stringToGameType(std::string const &);
GameType stringToIndividualGameType(std::string const &);
} // namespace GameTypeConv