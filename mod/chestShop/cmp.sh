g++ -fvisibility=hidden -shared -fPIC -Wl,-z,relro,-z,now -O3 -std=gnu++17 -I ../base/ -I ../../include main.cpp -o ../../out/chestShop.so
