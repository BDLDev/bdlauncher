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
