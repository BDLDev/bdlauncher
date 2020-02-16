# 手动编译依赖，如果用方法一安装，不需要安装依赖

| Name | Version | Ubuntu/Debian | Arch Linux |
| - | - | - | - |
| gcc | 9.2.0 | `apt install gcc` | `pacman -S gcc --needed` |
| g++ | 9.2.0 | `apt install g++` | `pacman -S gcc --needed` |
| readline(可选) | N/A | `apt install libreadline-dev` | `pacman -S readline --needed` |
| python | 3.7+ | `apt install python3 python3-pip` | `pacman -S python python-pip --needed` |
| ply[pip] | N/A | `pip3 install --user ply` | `pip install --user ply` |
| clang(可选) | 9.0.1 | `apt install clang-format` | `pacman -S clang --needed` |
# 安装到服务器

If you do not have a bedrock server, please download it from the [official website](https://www.minecraft.net/download/server/bedrock/) first

## 下载GitHub CI的预编译版本

1. 打开 [the GitHub Actions Artifact](https://github.com/Sysca11/bdlauncher/actions)
2. 下载最新的版本，RELEASE-CN...zip
3. 解压到服务器目录
4. 启动服务器

## 方法二：自己编译

(In your bedrock server folder)
```
git clone https://github.com/sysca11/bdlauncher bdlauncher-git -b master --depth=1
pushd bdlauncher-git
make install RELEASE=1 DESTDIR=..
popd
```

# 启动服务器

如果你自己编译 使用`./bdlauncher`<br>
否则 `LD_PRELOAD=./preload.so ./bedrock_server`

# Note

* BDL 替换了ctrl-c的功能，通过/stop安全关闭服务器
* 如果服务器卡死，可以 <pre>pkill -9 `pgrep bedrock_server`</pre> 来杀死服务器

# Next

see [Config.md](Config.md)
