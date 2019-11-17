# bdlauncher
Third-party BedrockServer launcher with mods support (1.13.x only)
<br>Only for Linux Servers
只支持Linux服务器<br>
<br>
<br>QQ group 955765957
<br>
# How to:
<pre>
#快速安装
#(In your server folder)在你的服务器目录
#安装原版服务端
wget https://minecraft.azureedge.net/bin-linux/bedrock-server-1.13.2.0.zip
unzip bedrock-server-1.13.2.0.zip

#安装mod及loader
git clone https://github.com/sysca11/bdlauncher -b master --depth=1
mkdir mods
cp -a ./bdlauncher/out/* ./mods
cp -a ./bdlauncher/mod.list ./mods
cp -a ./bdlauncher/config .
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
at doc/ folder
参见doc文件夹
</pre>
# Credits:
<pre>
HOOK Lib:https://github.com/Menooker/PFishHook
Json Parser:https://github.com/Tencent/rapidjson
BDS API:https://github.com/MCMrARM
BDS API:https://github.com/codehz/cobblestone 
</pre>

