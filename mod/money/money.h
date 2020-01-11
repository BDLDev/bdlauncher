#pragma once
#ifndef BDL_EXPORT
#define BDL_EXPORT __attribute__((visibility("default")))
#endif

#include<string_view>
using std::string_view;
BDL_EXPORT int get_money(string_view pn);
BDL_EXPORT void set_money(string_view pn,int am);
BDL_EXPORT bool red_money(string_view pn,int am);
BDL_EXPORT void add_money(string_view pn,int am);