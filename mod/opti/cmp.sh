g++ -fvisibility=hidden -shared -fPIC -Wl,-z,relro,-z,now -O3 -std=gnu++17 -I ../base/ -I ../../include opti.cpp -o ../../out/opti.so
