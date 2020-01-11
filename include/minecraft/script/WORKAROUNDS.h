#pragma once

#include "../core/types.h"

namespace entt {
template <typename> class Registry;
}

class Level;

namespace ScriptApi {
class WORKAROUNDS {
public:
  static void cacheActors(entt::Registry<unsigned int> &, Level &);
  static void helpRegisterActor(entt::Registry<unsigned int> &, ActorUniqueID const &, unsigned int &);

  struct tempActorComponent {
    ActorUniqueID id;
  };
};
} // namespace ScriptApi