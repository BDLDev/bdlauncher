#pragma once

#include <string>

struct CommandLexer {
  std::string value; // 0
  char *c_string;    // 8
  int unk16;         // 16
  int unk20;         // 20

  enum class TokenType;

  static bool isDigit(char);
  static bool isIdentifierCharacter(char);
  static bool isSpace(char);

  char *next();
  void step();
};