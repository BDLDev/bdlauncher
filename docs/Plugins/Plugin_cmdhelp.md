# cmdhelp.so
Translate this document into English later :D
## 简体中文
`/c` 打开预设命令列表  
`/reload_cmd` 重载配置  
`/runas <玩家名> <指令>` 以指定玩家的身份执行命令  
例如 /runas steve "money query"  
`/sched <时间秒:int> <玩家名> <cmdchain>` 延迟执行一个命令  
例如 /sched 5 Steve "say $name$ 114514"  
`/joinmsg [玩家名] [进服消息]` 自定义进服消息   
`/bc 消息`广播消息   
配置文件: cmd.json
```
[
    {
        "type":"timer",
        "time":5000,"shift":10,
        "cmd":"say timer!"
    },
```
> 这是一个定时器  
cmd为指令序列，具体用法请参见[base-cmd.md](https://github.com/Sysca11/bdlauncher/blob/master/docs/Plugins/Plugin_Base_cmd.md)  
time为秒数，shift为余数，开服时间除time余shift时执行  
可以有多个定时器
```
    {
        "type":"join",
        "cmd":"sched 10 %name% \"say $name$ 114514\""
    },
```
> 这是进服指令   
cmd为指令序列，具体用法请参见[base-cmd.md](https://github.com/Sysca11/bdlauncher/blob/master/docs/Plugins/Plugin_Base_cmd.md)
```
    {
        "type":"form",
        "text":"this is main menu",
        "title":"Main menu",
        "name":"root",
        "buttons":[
            ["kill me","money rd %name% 10","kill %name%"],
            ["open submenu","","execute %name% ~ ~ ~ c sub1"],
            ["buy sth","money rd %name% 10","give %name% diamond 10"],
            ["sell dirt","clear %name% dirt 0 9,clear %name% dirt 0 1","money add %name% 1,tell %name% dirt is cheapppp"],   
            ["magic","money rd %name% 10","!money add %name% 1;money add %name% 20"]]
    },
```
> text为gui内容，title为标题，name为指定的名字，通过`/c [name]`打开gui，默认主菜单名字root  
magic 为等概率随机执行两个指令，可以指定多个
```
    {
        "type":"form",   
        "text":"sub menu",
        "title":"sub",
        "name":"sub1",
        "buttons":[["me","","say %name% 114514"],["back","","execute %name% ~ ~ ~ c root"]]
    },
    
    {
        "type":"menuitem",
        "itemid":3
    }  
]
```
> `"itemid":3` 的意思是  
当玩家手持物品id为3(也就是泥土)，点地就会打开菜单

