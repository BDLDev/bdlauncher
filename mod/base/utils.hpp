
THook(void*,_ZN15CommandRegistry15registerCommandERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPKc22CommandPermissionLevel11CommandFlagSB_,uintptr_t a1,uintptr_t a2,uintptr_t a3,uintptr_t a4,uintptr_t a5,uintptr_t a6){
	return original(a1,a2,a3,a4,a5,0x40);
}
/*command cheat perm fixer*/
void call_sht(int d);
int tkl;
THook(void*,_ZN5Level4tickEv,Level& a){
    tkl++;
    if(tkl%(15*60*20)==0) //15min
        call_sht(SIGABRT); //send sigabrt for auto save data
    return original(a);
}