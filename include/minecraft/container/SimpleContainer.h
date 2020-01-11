#pragma once

#include "Container.h"

class SimpleContainer : public Container {
public:
  SimpleContainer(std::string const &, bool, int);
  void clearContent();
  virtual ~SimpleContainer();
  virtual ItemStack const &getItem(int) const;
  virtual void setItem(int, ItemStack const &);
  virtual int getContainerSize() const;
  virtual int getMaxStackSize() const;
  virtual void startOpen(Player &);
  virtual void stopOpen(Player &);
};