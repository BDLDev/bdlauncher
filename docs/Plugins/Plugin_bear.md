# bear.mod
[简体中文](#%e7%ae%80%e4%bd%93%e4%b8%ad%e6%96%87)
## English
server base anticheat

OP commands:

| Command | Description |
| ------- | ----------- |
| `/ac ban [name] [second]` | ban a player |
| `/ac unban [name]` | allow a player |
| `/ac kick [name]` | kick a player |
| `/ac invchk [name]` | check player's inventory |
| `/ac mute [name] [second]` | mute a player <br> When a player enters the server, his backpack information will be saved to the invdump folder. |
| `/ac reload` | reload configuration |

configuration file: `bear.json`

## 简体中文

服务器基础反作弊

包含隐身检查，物品封禁，部分限制

OP命令:

| 功能 | 指令 |
| - | - |
| 封禁玩家 | `/ac ban [玩家名] [秒](可选)` |
| 解除玩家的封禁 | `/ac unban [玩家]` |
| 强制踢出玩家 | `/ac kick [玩家]` |
| 以GUI的方式打开ban | `/ac bangui` |
| 检查玩家的背包 | `/ac invchk [玩家]` |
| 玩家进服自动保存背包到invdump文件夹
| 禁言玩家 | `/ac mute 玩家名 秒` |
| 重载配置 | `/ac reload` |

配置文件: `bear.json`
```json
{
    "FChatLimit": true,    // 聊天指令速度限制 4条/s
    "FPushChest": true,    // 限制推箱子（重启生效）
    "FDestroyCheck": true, // 限制破坏方块速度
    "FSpwanExp": true,     // 限制客户端经验生成（会导致无法磨石得经验等）
    "LogChest":true,       // 箱子日志
    "banitems": [11],      // 禁止使用物品，逗号分割，填物品id
    "warnitems": [12],     // 记录使用物品，逗号分割，填物品id
    "MAX_CHAT_LEN": 50     // 最大聊天长度
}
```
