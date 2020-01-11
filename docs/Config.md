# 1.config from an empty server
Now we can launch our server by `sh run.sh`,which outputs like this
```
[MOD] inject to 0x55555b2abd30 pid 82119
[MOD] main,start loading mods
[MOD] loading ./mods/base.so
[MOD] loading ./mods/opti.so
[MOD] loading ./mods/gui.so
...
[MOD] start loading
```
# 2.Adding mods.

edit mods/mod.list  
Notice that the mod.list must in a right order.
It means land.so(requires money.so) must be placed after money.so

Writing...