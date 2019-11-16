#land.so
!!!为了保护领地，领地会禁止全服耕地被踩坏

/land start 进入起点模式,点地选点
/land end 进入终点模式，点地选点
/land exit 退出选点模式
/land prebuy 计算选中区域价格
/land buy 选点之后买地

/land trust 人名 添加主人

/land trustgui GUI添加主人

/land untrust 人名 删除主人
/land sell 卖地（op可以强行卖）
/land query 查看当前领地主人
/land perm 数字 指定领地具体权限
1 = 破坏
2 = 空手使用
4 = /land query查看
8 = 攻击生物
数字为允许的权限之和，默认为4
例如你想让你的领地可以攻击生物，请使用/land perm 12，12=4+8(4=/land query查看、8=攻击生物)，恢复至初始状态请使用/land perm 4。
此外，领地权限分配可以让领地同时允许多个事件：
例如:你想让你的领地"既可以攻击生物又可以空手使用又可以使用/land query查看"
就可以使用/land perm 14，14=2+4+8(分别代表空手使用和/land query查看和攻击生物)
以此类推
常用权限：
6（可睡觉，开箱子）
14（可以攻击，睡觉，开箱子）
12（可攻击）

/reload_land 重载配置
配置文件 land.json
制定了领地每一块的价格
