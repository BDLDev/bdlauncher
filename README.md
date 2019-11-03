# bdlauncher
<br>Only for Linux Servers
只支持Linux服务器<br>
BedrockServer launcher with mods support (1.13 only)
<br>
<br>QQ group 955765957
<br>
# How to:
<pre>
快速安装
(In your server folder)在你的服务器目录

git clone https://github.com/sysca11/bdlauncher --depth=1
mkdir mods
cp -a ./bdlauncher/out/* ./mods
cp -a ./bdlauncher/mod.list ./mods
LD_LIBRARY_PATH=. LD_PRELOAD=./mods/a.so ./bedrock_server
</pre>

# 编译:
<pre>
sh cmp.sh #编译mod加载器
cd mod
sh all.sh #编译mod
#输出结果在out文件夹
</pre>
# DOC:
<pre>
mods/mod.list是插件列表，条目顺序是插件加载顺序，不建议修改
如果要禁用插件，或者增加插件，直接删除对应行或给最后一行添加即可

opti.so
实验性服务器优化
（更多优化请参见https://github.com/sysca11/rocket)
base.so
基础插件（required）
bear.so
ban支持 服务器log
money.so
经济 商店
land.so
领地
tp.so
tpa home支持
第三方插件
https://github.com/thirteenc13/bdlauncher-mods
</pre>
<pre>
所有玩家名带空格的，可以写成"bla bla"
例如
/money query "114514 1919810"

!!!anticheat会禁止推动容器方块，新版本已经解决了容器消失问题
!!!领地插件为了保护耕地，会让耕地块不会被踩坏


经济
初始50块
/money query 查钱
或/money query 玩家名
op可以/money add 钱数
/money pay 玩家ID 钱数 玩家间转账(单次最大10000)
家
/home add 名字
/home ls 查看
/home go 名字 回家
/warp ls查看
/warp 地名
/warp add 添加点（op）

玩家名可以模糊匹配，例如AbCde 可以只输入ab
/tpa f 玩家名 让玩家传送到你
/tpa t 玩家名 你到玩家

/tpa ac 同意
/tpa de 拒绝
领地：
/land start 选择起点（你站的地方）
/land end 选择终点
/land buy 选点之后买地(1格10块）
/land trust 人名 添加主人
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

/suicide 自杀
/shop ls
/shop buy 商店名
op：
/ban 名字 [seconds]
/unban 名字
可选时间（秒）
/shop add 名字 物品 数量 金钱
如 /shop add 玩家买钻石 diamond 1 50
数量小于0是卖
/shop del 名字
</pre>
# How it works:
<pre>
Thanks to https://github.com/Menooker/PFishHook and bedrock_server with optimization level 0 ,we can easily hook functions.
</pre>

