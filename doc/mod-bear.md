# bear.so
服务器基础反作弊  
op：  
/ban 名字 [seconds]  
/ban sxc 100  
封禁sxc 100秒  
/unban 名字  
/skick 名字  #强行kick玩家
/bangui  #显示guiban
/bear_dbg #打开debug开关，点地显示手里物品id

/reload_bear 重载配置  
配置文件 bear.json  

{"FChatLimit": true, #聊天指令速度限制 4条/s  
"FPushChest": true,  #限制推箱子（重启生效）  
"FDestroyCheck": true,  #限制破坏方块速度  
"FSpwanExp": true,  #限制客户端经验生成（会导致无法磨石得经验等）  
"banitems": [11], #禁止使用物品，逗号分割，填物品id  
 "warnitems": [12]} #记录使用物品，逗号分割，填物品id  

