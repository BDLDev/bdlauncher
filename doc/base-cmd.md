#指令序列
指令序列为一串序列，包含要执行的指令。一般为链式执行。
chain类型：
1.普通chain：
多个指令用,（英文）分割，用%name%替换玩家名
例如：give %name% diamond 1,tell %name% success
2.随机chain：
!开头
由多个普通chain组成，每个chain用;分割，每个chain被执行概率相等，只会执行一个chain
例如：!give %name% diamond 1,tell %name% success;give %name% dirt 1,tell %name% falied

