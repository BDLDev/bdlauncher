#cmdhelp.so
/c打开预设命令列表
/reload_cmd 重载配置

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
/×
这是进服指令
cmd为指令序列（参见base-cmd.md)
×/
{"type":"define",
"name":"STOP SERVER AS OP use 100 money",
"cond":"money rd %name% 100",
"cmd":"stop"}
/×
这是预设指令
name 预设指令名（/c显示的）
cond为指令序列，当且仅当cond执行成功时，才以服务器控制台权限执行cmd
cmd为指令序列（参见base-cmd.md)
可以用来做商店
×/
]

