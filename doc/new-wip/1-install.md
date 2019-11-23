<h1>bdlauncher</h1>
Third-party BedrockServer launcher with mods support (1.13.x only)
# Install it to BDS
<pre>
(In your server folder)
git clone https://github.com/sysca11/bdlauncher -b master --depth=1  
mkdir mods  
cp -a ./bdlauncher/out/* ./mods  
cp -a ./bdlauncher/mod.list ./mods  
cp -a ./bdlauncher/config .  
</pre>
# Upgrade from an old version
<pre>
cd bdlauncher
git pull
cp -a ./bdlauncher/out/* ../mods  
cp -a ./bdlauncher/mod.list ../mods
cp -a ./bdlauncher/config ..  
(in general,you might need to overwrite your configs,because new version uses a new format of config.)
</pre>
# Launch server
<pre>
sh run.sh
</pre>
# Note
<pre>
BDL replaced SIGINT handler so that server will handle ctrl-c safely(use /stop command).  
If server hangs,you can use pkill -9 `pgrep bedrock_server` to kill your server. 
</pre>
# Next
see 2-config-guide.md
