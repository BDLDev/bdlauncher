g++ -std=gnu++17 -I include/ main.cpp hook.cpp loader.cpp libPFishHook.a cmdhelper.cpp -shared -fPIC -ldl -Ofast -o out/a.so

