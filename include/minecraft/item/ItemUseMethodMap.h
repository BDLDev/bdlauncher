#pragma once

#include "../core/types.h"

#include <string>

class ItemUseMethodMap {
public:
  ItemUseMethod getItemUseMethod(std::string const &);
  static std::string const &getItemUseMethodName(ItemUseMethod);
};