# WARNING:1.14 only for testing

# Compile requirements

| Name | Version | Ubuntu/Debian | Arch Linux |
| - | - | - | - |
| gcc | 9.2.0 | `apt install gcc` | `pacman -S gcc --needed` |
| g++ | 9.2.0 | `apt install g++` | `pacman -S gcc --needed` |
| readline | N/A | `apt install libreadline-dev` | `pacman -S readline --needed` |
| python | 3.7+ | `apt install python3 python3-pip` | `pacman -S python python-pip --needed` |
| ply[pip] | N/A | `pip3 install --user ply` | `pip install --user ply` |
| clang | 9.0.1 | `apt install clang-format` | `pacman -S clang --needed` |
# Install it to BDS

If you do not have a bedrock server, please download it from the [official website](https://www.minecraft.net/download/server/bedrock/) first

## Download prebuilt binary and install

1. Open [the GitHub Actions Artifact](https://github.com/Sysca11/bdlauncher/actions)
2. Download latest building
3. Unzip downloaded file to the directory of bedrock server
4. Launcher server

## Compile and install

(In your bedrock server folder)
```
git clone https://github.com/sysca11/bdlauncher bdlauncher-git -b master --depth=1
pushd bdlauncher-git
make install RELEASE=1 DESTDIR=..
popd
```

# Upgrade from an old version

```
pushd bdlauncher-git
git pull
make install RELEASE=1 DESTDIR=..
popd
```

# Launch server

`./bdlauncher`

# Note

* BDL replaced SIGINT handler so that server will handle ctrl-c safely(use /stop command).
* If server hangs,you can use pkill -9 `pgrep bedrock_server` to kill your server.

# Next

see [Config.md](Config.md)
