g++ -shared -fPIC -Wl,-z,relro,-z,now -Ofast -std=gnu++17 -I ../money/ -I ../base/ -I ../../include land.cpp -o ../../out/land.so

