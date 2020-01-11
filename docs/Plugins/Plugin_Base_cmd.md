# cmd.so
[简体中文](#%e7%ae%80%e4%bd%93%e4%b8%ad%e6%96%87)
## English
### Command sequence
A command sequence is a sequence of instructions that contains instructions to be executed. It is generally executed in chains.  
chain type:
1. normal chain：  
Multiple commands can be separated by using";", % name% represents the player ID  
for example: `"give %name% diamond 1,tell %name% success"` 
1. random chain：  
Begins with "!" And consists of multiple ordinary chains, each chain is separated by ";" each chain is executed with equal probability, and only one chain  
for example: `"!give %name% diamond 1,tell %name% success;give %name% dirt 1,tell %name% falied"`

## 简体中文
### 指令序列  
指令序列为一串序列，包含要执行的指令。一般为链式执行。  
chain类型:   
1. 普通chain:   
多个指令用,（英文）分割，用%name%替换玩家名  
例如: `"give %name% diamond 1,tell %name% success"`  
2. 随机chain:   
感叹号开头，由多个普通chain组成，每个chain用;分割，每个chain被执行概率相等，只会执行一个chain  
例如: `"!give %name% diamond 1,tell %name% success;give %name% dirt 1,tell %name% falied"`

