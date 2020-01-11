g++ -std=gnu++17 -I include/ main.cpp hook.cpp loader.cpp libPFishHook.a -shared -flto -fPIC -ldl -O3 -Wl,-z,relro,-z,now  -o out/a.so
