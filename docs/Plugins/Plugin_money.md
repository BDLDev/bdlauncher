# money.so
[简体中文](#%e7%ae%80%e4%bd%93%e4%b8%ad%e6%96%87)
## English
### Commands:
`/money query` check your wallet  
`/money query [player]` check others wallet   
`/money pay [player] [money]` Transfer money to a player  

## OP commands
`/money set [player] [money]` Set a player's money  
`/money add [player] [money]` Give players money  
`/money rd [player] [money]` Deduct money Can be used with command_block  
`/money paygui` Open the transfer interface  
`/reload_money` reload config  

config: config/money.json  
init_money:Player initial money

## 简体中文
## 命令
`/money query` 查钱  
`/money query [玩家名]` 查询目标玩家的金钱  
`/money pay [玩家ID] [钱数]` 玩家间转账(单次最大10000)  
## OP命令
`/money set [玩家ID] [钱数]` 将玩家的金钱设置为指定值  
`/money add [玩家ID] [钱数]` 为玩家增加一些金钱  
`/money rd [玩家ID] [钱数]` 扣钱，如果扣钱成功，会触发success，可以做链式命令方块或者cmdchain内cond使用  
`/money paygui` 使用GUI来转账  
`/reload_money` 重载配置  

配置文件: money.json  
init_money: 玩家初始金钱  
