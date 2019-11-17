#pragma once
#ifndef BDL_EXPORT
#define BDL_EXPORT __attribute__((visibility("default")))
#endif

BDL_EXPORT int get_money(const string& pn);
BDL_EXPORT void set_money(const string& pn,int am);
BDL_EXPORT bool red_money(const string& pn,int am);
BDL_EXPORT void add_money(const string& pn,int am);