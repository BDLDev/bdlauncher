# cmdhelp.so
/c 打开预设命令列表  
/reload_cmd 重载配置  
<pre>
配置文件 cmd.json  
[  
{"type":"timer",  
"time":20,"shift":10,  
"cmd":"say timer!"},  

/*  
这是一个定时器  
cmd为指令序列（参见base-cmd.md)  
time为秒数，shift为余数，开服时间除time余shift时执行  
可以有多个定时器  
*/  

{"type":"join",  
"cmd":"say %name% hellp"}, 

/*  
这是进服指令  
cmd为指令序列（参见base-cmd.md)  
*/

[
{"type":"timer",
"time":5000,"shift":10,
"cmd":"say timer!"},
{"type":"join",
"cmd":"say %name% hellp"},

/*text为gui内容，title为标题，name为指定的名字，通过/c 名字打开gui,默认主菜单名字root*/

{"type":"form",
"text":"this is main menu",
"title":"Main menu",
"name":"root",
"buttons":[["kill me","money rd %name% 10","kill %name%"],
["open submenu","","execute %name% ~ ~ ~ c sub1"],
["buy sth","money rd %name% 10","give %name% diamond 10"],
["sell dirt","clear %name% dirt 0 9,clear %name dirt 0 1","money add %name% 1,tell %name% dirt is cheapppp"],
["magic","money rd %name% 10","!money add %name% 1;money add %name% 20"]]},

/*magic 为等概率随机执行两个指令 可以指定多个*/

{"type":"form",
"text":"sub menu",
"title":"sub",
"name":"sub1",
"buttons":[["me","","say %name% 114514"],["back","","execute %name% ~ ~ ~ c root"]]},
{"type":"menuitem","itemid":3}

/*物品id为3点地打开菜单*/

]
]
</pre>

