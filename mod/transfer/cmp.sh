MOD_NAME="transfer"
${BDL_CXX} ${BDL_CXXFLAG} -fvisibility=hidden -shared -fPIC -std=gnu++17 -I ../../include main.cpp ${BDL_ADDLINK} -o ../../out/${MOD_NAME}.so
