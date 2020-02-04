#pragma once
#include <string_view>
#include <functional>
#include <vector>
#include <cassert>
#include <minecraft/actor/Player.h>
#include "../base/stkbuf.hpp"

constexpr std::string_view button_json = "{\"type\":\"form\",\"title\":\"";
constexpr std::string_view input_json  = "{\"type\":\"custom_form\",\"title\":\""; // content
constexpr std::string_view split_p1 = ",";
constexpr std::string_view split_p2 = "\",\"content\":\"";
struct SharedForm {
  bool needfree;
  bool isInput;
  bool hasSerialed;
  int fid;
  SPBuf<2048> buf;
  vector<string_view> labels;
  std::function<void(ServerPlayer *, string_view, int)> cb;
  SharedForm(string_view title, string_view cont, bool nedfree = true, bool isInp = false) {
    needfree    = nedfree;
    isInput     = isInp;
    hasSerialed = false;
    if (isInput) {
      buf.write(input_json);
      buf.write(title);
      buf.write("\",\"content\":[");
    } else {
      buf.write(button_json);
      buf.write(title);
      buf.write(split_p2);
      buf.write(cont);
      buf.write("\",\"buttons\":[");
    }
  }
  void process(ServerPlayer *sp, string_view d) {
    if (d.size() == 0) return;
    if (d[0] == 'n') return;
    if (isInput)
      cb(sp, d.substr(2, d.size() - 5), 0);
    else {
      auto idx = atoi(d);
      if (idx >= 0 && idx < (int) labels.size()) cb(sp, labels[idx], idx);
    }
  }
  void addInput(string_view text) {
    assert(isInput);
    buf.write("{\"type\":\"input\",\"placeholder\":null,\"default\":null,\"text\":\"");
    buf.write(text);
    buf.write("\"}]}"); // end everything
  }
  void addButton(string_view text) {
    assert(!isInput);
    if (buf.buf[buf.ptr - 1] == '}') { buf.write(split_p1); }
    buf.write("{\"text\":\"");
    labels.emplace_back(buf.buf + buf.ptr, text.size());
    buf.write(text);
    buf.write("\"}");
  }
  string_view serial() {
    if (hasSerialed || isInput) return buf.get();
    buf.write("]}"); // end button json
    hasSerialed = true;
    return buf.get();
  }
};

BDL_EXPORT void sendForm(ServerPlayer &sp, SharedForm *fm);
BDL_EXPORT SharedForm *getForm(string_view title, string_view cont, bool isInp = false);
BDL_EXPORT void gui_ChoosePlayer(
    ServerPlayer *sp, string_view text, string_view title, std::function<void(ServerPlayer *, string_view)> const &cb);
