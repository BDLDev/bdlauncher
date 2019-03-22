# bdlauncher
BedRockServer launcher with mods support<br>
Notice: CentOS and low version GLIBC system support(Neither docker nor root is required):https://www.minebbs.com/threads/centos-bds-root-docker.2424/
# (BDS 1.9 TESTED,1.10 TESTING)
(Some codes from https://github.com/codehz/BedrockMod.  Thanks @codehz for decompiling BDS.)
LD_LIBRARY_PATH=. LD_PRELOAD=./bin/launch.so ./bedrock_server
<br>land will not work in 1.10<br>
开服方法：
先把bin文件夹里面除launch.so外的其他.so放到mods文件夹
然后执行
<pre>LD_LIBRARY_PATH=. LD_PRELOAD=./bin/launch.so ./bedrock_server</pre>

put mods(bin/a.so,amoney.so,ban.so,land.so) into folder mods,and start the server.

example plugin intro:
范例插件用法

# ban 黑名单
<pre>
/ban ［PlayerName］
/unban ［PlayerName］
</pre>
# money 简单经济
<pre>
/money query [Playername] 
查询余额（初始500)
/money set [playername] [int:money] 
设置钱
/money add [PlayerName] [int money] 
添加钱
</pre>
 
# land 迫真领地
 <pre>
/land start
/land end
then touch the ground to determine the pos of land 
先输指令，然后点地（右键）确定起点终点
/land buy
buy the land 买(价格 每个方块10）
/land invite ［PlayerName］
share permissions with others (分享)
/land sell
sell the land on which you stand.
(OP can force sell lands) （卖 管理可以卖掉任何领地)
 </pre>
