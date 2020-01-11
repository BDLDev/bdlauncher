# 1.config from an empty server
Now we can launch our server by `./bdlauncher`,which outputs like this
```
[MOD] inject to 0x55555b2abd30 pid 82119
[MOD] main,start loading mods
[MOD] loading ./mods/base.mod
[MOD] loading ./mods/opti.mod
[MOD] loading ./mods/gui.mod
...
[MOD] start loading
```
# 2.Adding mods.

edit mods/mod.list  
Notice that the mod.list must in a right order.
It means land.mod(requires money.mod) must be placed after money.mod

Writing...