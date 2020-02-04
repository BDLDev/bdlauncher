#pragma once

#include <cstring>
extern "C"{
void _ZN25ActorDefinitionIdentifierD2Ev(void *);
}

class ActorDefinitionIdentifier {
public:
  char filler[sizeof(std::string) * 5];
  ActorDefinitionIdentifier(std::string const &);
  ~ActorDefinitionIdentifier() { _ZN25ActorDefinitionIdentifierD2Ev(this); }
};