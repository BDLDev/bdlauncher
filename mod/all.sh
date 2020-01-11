export BDL_CXX="g++"
export BDL_CXXFLAG=" -Ofast -flto -Wl,-z,relro,-z,now -DLANG_EN "
#export BDL_CXXFLAG=" -g -fsanitize=undefined"
#export BDL_ADDLINK="../libleveldb.a"
cd base;sh cmp.sh;cd ..;
cd opti;sh cmp.sh;cd ..;
cd bear;sh cmp.sh;cd ..;
cd land;sh cmp.sh;cd ..;
cd money;sh cmp.sh;cd ..;
cd tptp;sh cmp.sh;cd ..;
cd gui;sh cmp.sh;cd ..;
#cd antixray;sh cmp.sh;cd ..;
cd chestShop;sh cmp.sh;cd ..;
cd cdk;sh cmp.sh;cd ..;
cd transfer;sh cmp.sh;cd ..;
cd cmdhelp;sh cmp.sh;cd ..;
cd killbonus;sh cmp.sh;cd ..;
cd protect;sh cmp.sh;cd ..;
cd vars;sh cmp.sh;cd ..;
#cd invcheck;sh cmp.sh;cd ..;
cd map;sh cmp.sh;cd ..;
#cd wtf;sh cmp.sh;cd ..;
cd custname;sh cmp.sh;cd ..;
cd bossbar;sh cmp.sh;cd ..;
