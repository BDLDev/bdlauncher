#include <Loader.h>
#include <logger.h>
#include <MC.h>
#include <thread>
#include <fstream>

#include "rpcws.hpp"

using namespace rpc;
using namespace rpcws;

struct do_init {
  RPC server;
  std::thread thrd;

  static std::string getAddress() {
    Json::Reader reader;
    Json::Value value;
    std::ifstream ifs{"config/rpc.json"};
    if (!reader.parse(ifs, value)) {
      auto msg = reader.getFormattedErrorMessages();
      do_log("%s", msg.c_str());
      exit(1);
    }
    auto address = value["address"].asString("ws+unix://rpc.socket");
    return address;
  }

  do_init() : server(std::make_unique<server_wsio>(getAddress())), thrd([&] { server.start(); }) {
    server.reg("ping", [](std::shared_ptr<server_io::client>, Json::Value const &) -> Json::Value { return "pong"; });
  }

  ~do_init() {
    server.stop();
    if (thrd.joinable()) thrd.join();
    do_log("RPC stopped");
  }
} init;

// For compatiable
extern void load_helper(std::list<string> &modlist);
extern "C" {
BDL_EXPORT void mod_init(std::list<string> &modlist) { load_helper(modlist); }
}
