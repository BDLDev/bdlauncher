clang++ -fPIC -O3 -shared main.cpp libPFishHook.a mods.cpp -o a.so -ldl -I ../PFishHook/ -fsanitize=undefined
