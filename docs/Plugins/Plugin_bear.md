# bear.so
[简体中文](#%e7%ae%80%e4%bd%93%e4%b8%ad%e6%96%87)
## English
server base anticheat  
OP commands:  
`/ban [name] [second]` ban a player  
`/unban [name]` allow a player  
`/skick [name]` kick a player  
`/bear_dbg` debug, tap the ground to display the ID of the handheld item  
`/invcheck [name]` check player's inventory  
`/mute [name] [second]` mute a player   
When a player enters the server, his backpack information will be saved to the invdump folder.

`/reload_bear` reload configuration  
configuration file: bear.json
## 简体中文
服务器基础反作弊  
包含隐身检查，物品封禁，部分限制  
OP命令:  
封禁玩家: `/ban [玩家名] [秒](可选)`  
解除玩家的封禁: `/unban [玩家]`  
强制踢出玩家: `/skick [玩家]`     
以GUI的方式打开ban: `/bangui`  
打开debug开关，点地显示手里物品id: `/bear_dbg`  
检查玩家的背包: `/invcheck [玩家]`  
玩家进服自动保存背包到invdump文件夹   
禁言玩家：`/mute 玩家名 秒`   
`/reload_bear` 重载配置  
配置文件: bear.json  
```
{"FChatLimit": true, #聊天指令速度限制 4条/s  
"FPushChest": true,  #限制推箱子（重启生效）  
"FDestroyCheck": true,  #限制破坏方块速度  
"FSpwanExp": true,  #限制客户端经验生成（会导致无法磨石得经验等）  
"LogChest":true, #箱子日志  
"banitems": [11], #禁止使用物品，逗号分割，填物品id  
 "warnitems": [12],#记录使用物品，逗号分割，填物品id  
"MAX_CHAT_LEN":50 #最大聊天长度   
} 
```