g++ -fvisibility=hidden -shared -fPIC -Wl,-z,relro,-z,now -O3 -std=gnu++17 -I ../base/ -I ../../include map.cpp -o ../../out/map.so

