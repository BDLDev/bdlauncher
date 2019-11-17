g++ -fvisibility=hidden -shared -fPIC -Wl,-z,relro,-z,now -O3 -std=gnu++17 -I ../base/ -I ../../include tptp.cpp -o ../../out/tp.so
