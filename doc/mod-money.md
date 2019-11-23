# money.so
/money query 查钱  
或/money query 玩家名  
/money pay 玩家ID 钱数 玩家间转账(单次最大10000)  

op指令  
/money set Steve 10000  
/money add Steve 10000  
/money rd Steve 10000 扣钱，如果扣钱成功，会触发success，可以做链式命令方块或者cmdchain内cond使用  

GUI指令  
/money paygui  

/reload_money 重载配置  
配置文件 money.json  
init_money:玩家初始金钱  
