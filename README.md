# bdlauncher

BedRockServer launcher with mods support (for BedRock Edition 1.12) <br>

低版本CentOS Ubuntu免升级启动方法<br>
Notice: CentOS and low version GLIBC system support(Neither docker nor root is required):https://www.minebbs.com/threads/centos-bds-root-docker.2424/

# How to:
<pre>
如何安装
(In your server folder)在你的服务器目录
mkdir mods
cd mods

nano mod.list
opti.so
base.so
bear.so
money.so
land.so
tp.so

cp a.so ..
cd ..
LD_LIBRARY_PATH=. LD_PRELOAD=a.so ./bedrock_server
</pre>
# Compile:
<pre>
sh cmp.sh
cd mod
sh all.sh
</pre>
# DOC:
<pre>
opti.so
实验性服务器优化
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
</pre>
<pre>
经济
初始250块
/money query查钱
或/money query 玩家名
op可以/money add 钱数
家
/home add 名字
/home ls 查看
/home go 名字 回家
/warp ls查看
/warp 地名
/warp add 添加点（op）
/tpa f 玩家名 让玩家传送到你
/tpa t 玩家名 你到玩家
/tpa ac 同意
/tpa de 拒绝
/tpa rand 随机传送到野外，可能卡区块，卡了就退了重进
领地：
/land start选择起点（你站的地方）
/land end选择终点
/land buy选点之后买地(1格1块）
/land trust 人名 添加主人
/land sell卖地
/land test查看当前领地主人
/suicide 自杀
/shop ls
/shop buy 商店名
op：
/ban 名字 [seconds]
/unban 名字
可选时间（秒）
/shop add 名字 数量 金钱
数量小于0是卖
/shop del 名字
</pre>
