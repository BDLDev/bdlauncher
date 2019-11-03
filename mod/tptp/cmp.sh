g++ -shared -fPIC -Wl,-z,relro,-z,now -Ofast -std=gnu++17 -I ../base/ -I ../../include tptp.cpp -o ../../out/tp.so

