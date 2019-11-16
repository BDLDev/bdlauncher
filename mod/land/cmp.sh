g++ -fvisibility=hidden -shared -fPIC -Wl,-z,relro,-z,now -O3 -std=gnu++17 -I ../money/ -I ../base/ -I ../../include land.cpp -o ../../out/land.so

