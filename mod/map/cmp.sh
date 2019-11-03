g++ -shared -fPIC -Wl,-z,relro,-z,now -Ofast -std=gnu++17 -I ../base/ -I ../../include map.cpp -o ../../out/map.so

