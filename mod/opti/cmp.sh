g++ -shared -fPIC -Wl,-z,relro,-z,now -Ofast -std=gnu++17 -I ../base/ -I ../../include opti.cpp -o ../../out/opti.so

