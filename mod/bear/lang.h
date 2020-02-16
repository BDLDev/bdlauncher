#pragma once
#include <lang_detect.h>
#if LANG == CN
#  define YOU_R_BANNED "§c你在当前服务器的黑名单内!"
#  define BANNED_ITEM "§c无法使用违禁物品"
#  define URMUTED "§c你已被禁言"
#  define TLONGCHAT "§c消息长度过大"
#else
#  define YOU_R_BANNED "§cYou're banned!"
#  define BANNED_ITEM "§cBanned item!"
#  define URMUTED "You're muted"
#define TLONGCHAT "too long chat"
#endif