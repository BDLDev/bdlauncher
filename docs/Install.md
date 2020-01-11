# WARNING:1.14 only for testing
# Install it to BDS
If you do not have a bedrock server, please download it from the [official website](https://www.minecraft.net/download/server/bedrock/) first
```
(In your bedrock server folder)
git clone https://github.com/sysca11/bdlauncher -b master --depth=1  
mkdir mods  
cp -a bdlauncher/out/* ./mods
cp -a bdlauncher/mod.list ./mods
cp -a bdlauncher/config .
cp -a bdlauncher/run.sh .
```
# Upgrade from an old version
```
cd bdlauncher
git pull
cd ..
cp -a bdlauncher/out/* ./mods  
cp -a bdlauncher/mod.list ./mods
cp -a bdlauncher/config .  
(in general, you might need to overwrite your configs, because new version uses a new format of config.)
```
# Launch server
`./run.sh`
# Note
BDL replaced SIGINT handler so that server will handle ctrl-c safely(use /stop command).  
If server hangs,you can use pkill -9 `pgrep bedrock_server` to kill your server.
# Next
see [Config.md](https://github.com/Sysca11/bdlauncher/blob/master/docs/Config.md)