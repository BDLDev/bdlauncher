# Compile it by yourself
Requirements:   
<pre>
g++ 9 or later
Configure your compiler in cmp.sh and all.sh
</pre>
`sh cmp.sh` Compile the loader(a.so)   
`cd mods;sh all.sh` Compile mods   
`cd mods/xxx;sh cmp.sh` Compile a mod,YOU MUST CONFIGURE CFLAGS AND CXX FIRST.See all.sh for details.   
需要g++9或以上  
`sh cmp.sh` 编译loader(a.so)   
`cd mods;sh all.sh` 编译 mods   
`cd mods/xxx;sh cmp.sh` 编译 一个 mod，必须先配置好环境变量，参见all.sh内的export   
