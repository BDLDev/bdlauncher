
THook(void *, _ZN15CommandRegistry15registerCommandERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPKc22CommandPermissionLevel11CommandFlagSB_, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5, uintptr_t a6)
{
    return original(a1, a2, a3, a4, a5, 0x40);
}
/*command cheat perm fixer*/
static ItemRegistry *ItemReg;
extern "C"{
    void _ZN12ItemRegistry12lookupByNameERiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(char*,int&,const string*);
    void _ZN9ItemStack10EMPTY_ITEME();
    void _ZN7WeakPtrI4ItemE5resetEv(char*);
    void _ZN12ItemRegistry7getItemEs(char*,short);
}
ItemStack* createItemStack(string const& name,unsigned char amo){
    ItemStack* ik=new ItemStack();
    auto res=createItemStack_static(name,amo,ik);
    if(res==nullptr){
        free(ik);
        return nullptr;
    }
    return ik;
}
ItemStack* createItemStack_static(string const& name,unsigned char amo,ItemStack* stk){
    char filler[16];
    memset(filler,0,sizeof(filler));
    int unk=0;
    _ZN12ItemRegistry12lookupByNameERiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(filler,unk,&name);
    Item* ite=nullptr;
    if(access(filler,Item**,0)){
        ite=*access(filler,Item**,0);
    }
    _ZN7WeakPtrI4ItemE5resetEv(filler);
    if(!ite) return nullptr;
    ItemStack* ik=new (stk)ItemStack(*ite);
    ik->setStackSize(amo);
    return stk;
}
ItemStack* createItemStack(short id,short aux,unsigned char amo){
    ItemStack* ik=new ItemStack();
    auto res=createItemStack_static(id,aux,amo,ik);
    if(res==nullptr){
        free(ik);
        return nullptr;
    }
    return ik;
}
ItemStack* createItemStack_static(short id,short aux,unsigned char amo,ItemStack* stk){
    char filler[16];
    memset(filler,0,sizeof(filler));
    int unk=0;
    _ZN12ItemRegistry7getItemEs(filler,id);
    Item* ite=nullptr;
    if(access(filler,Item**,0)){
        ite=*access(filler,Item**,0);
    }
    _ZN7WeakPtrI4ItemE5resetEv(filler);
    if(!ite) return nullptr;
    ItemStack* ik=new (stk)ItemStack(*ite);
    ik->setStackSize(amo);
    ik->setAuxValue(aux);
    printf(ik->toString().c_str());
    return stk;
}
void giveItem(ServerPlayer& sp,ItemStack* is){
    auto trm=sp.getTransactionManager();
    trm->_createServerSideAction(*(ItemStack*)_ZN9ItemStack10EMPTY_ITEME,*is);
    sp.getSupplies().add(*is,false);
    sp.sendInventory(false);
}
bool takeItem_unsafe(ServerPlayer& sp,ItemStack* is){
    auto trm=sp.getTransactionManager();
    trm->_createServerSideAction(*is,*(ItemStack*)_ZN9ItemStack10EMPTY_ITEME);
    auto ret=sp.getSupplies().removeResource(*is);
    sp.sendInventory(false);
    return ret;
}
bool takeItem(ServerPlayer& sp,ItemStack* is){
    auto& x=sp.getSupplies();
    int sz=x.getContainerSize((ContainerID)0ul);
    int sigmasz=0;
    short id=is->getId();
    short aux=is->getAuxValue();
    for(int i=0;i<sz;++i){
        auto& item=x.getItem(i,(ContainerID)0ul);
        if(item.getId()==id && item.getAuxValue()==aux){
            sigmasz+=item.getStackSize();
        }
    }
    if(sigmasz>=is->getStackSize()){
        return takeItem_unsafe(sp,is);
    }
    return false;
}
ActorUniqueID summon(BlockSource& bs,Vec3 const& vc,string const& name){
    ActorUniqueID auid;
    ActorDefinitionIdentifier adi(name);
    CommandUtils::spawnEntityAt(bs,vc,adi,auid);
    return auid;
}