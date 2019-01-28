#include<bits/stdc++.h>
#include "../bdlaunch/launch/mods.h"
extern "C"{
	void mod_init();
};
void* gg;
bool fk1(){
	printf("nest hook1\n");
	return false;
}
bool fk2(){
	printf("nest hook2\n");	
	return ((bool(*)())gg)();
}
void mod_init(){
	printf("Hello World\n");
	MCHook("_ZNK17ConnectionRequest9isEduModeEv",(void*)fk1);
	gg=MCHook("_ZNK17ConnectionRequest9isEduModeEv",(void*)fk2);
}
