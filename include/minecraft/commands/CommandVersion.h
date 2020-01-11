#pragma once

class CommandVersion {
  int min, max;

public:
  CommandVersion(int min, int max);
  static unsigned int CurrentVersion;
};