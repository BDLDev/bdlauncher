# land.so
[简体中文](#%e7%ae%80%e4%bd%93%e4%b8%ad%e6%96%87)
## English
`/land a` Click on the box to choose a starting point  
`/land b` Click another square to select another point  
`/land exit` Exit selection mode  
`/land buy` Buy land  
`/land trust [player]` add guest  
`/land trustgui` open interface to add guest  
`/land untrust [name]` remove guest  
`/land untrustgui` open interface to remove guest  
`/land sell` sell land(OP can sell player's land)  
`/land query` view master of this land  
`/land give [name]` Give your land to others  

`/land perm [digital]` Specify what unauthorized players can do in your territory  
```
    PERM_USE=2,  use block
    PERM_ATK=4,  attack
    PERM_BUILD=8,  place and break
    PERM_POPITEM=16,  Item display box
    PERM_INTERWITHACTOR=32  Armor stand
The number of permissions is the sum of the available permissions
such as: 2=sleep
6=sleep and attack
```
`/reload_land` reload config  
config: land.json  
buy_price: Price per square

## 简体中文
`/land a` 进入起点模式,点地选点  
`/land b` 进入终点模式，点地选点  
`/land exit` 退出选点模式  
`/land buy` 选点之后买地  
`/land trust [玩家ID]` 添加主人  
`/land trustgui` GUI添加主人  
`/land untrust [玩家ID]` 删除主人  
`/land untrustgui` 删除主人GUI  
`/land sell` 卖地（op可以强行卖）  
`/land query` 查看当前领地主人  
`/land give [玩家ID]` 转让权限  

> 注意，只有land的第一个owner拥有trust,untrust,sell,perm的权限，trust后的主人只有领地的其他权限。
可以通过land give 转让全部权限给别人

/land perm 数字 指定领地具体权限  
```
    PERM_USE=2,  使用方块权限
    PERM_ATK=4,  攻击权限
    PERM_BUILD=8,  建造破坏权限
    PERM_POPITEM=16,  物品展示框权限
    PERM_INTERWITHACTOR=32  盔甲架等交互权限
权限数字为可以使用的权限之和
例如 2=可以睡觉，开箱子
6=可以睡觉，开箱子，攻击生物
```

`/reload_land` 重载配置  
配置文件: land.json  
buy_price: 制定了领地每一块的价格  
