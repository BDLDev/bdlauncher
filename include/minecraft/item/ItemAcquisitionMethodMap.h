#pragma once

#include "../core/types.h"

#include <string>

class ItemAcquisitionMethodMap {
public:
  static ItemAcquisitionMethod getItemAcquisitionMethod(std::string const &);
  static std::string const &getItemAcquisitionMethodName(ItemAcquisitionMethod method);
};