#pragma once

#include "global.h"

#include <functional>

class Minecraft;

class ServerInstance {
public:
  MakeAccessor(getMinecraft, Minecraft *, 32);

  void queueForServerThread(std::function<void()> fn);
};