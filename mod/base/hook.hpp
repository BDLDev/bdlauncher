/*
    typedef int(*hook_1_fn)(Player* a0,Actor & a1);
    static list<void*> ev_attack;
    void reg_attack(void* a){
        ev_attack.push_back(a);
    }
    static int onEvent_attack(Player* a0,Actor & a1){
        for(auto i:ev_attack){
            int res=((hook_1_fn)i)(a0,a1);
            if(res==0) return 0;
        }
        return 1;
    }
    static struct hook_1{
        hook_1_fn orig;
        static uint64_t onuse(Player* a0,Actor & a1);
        hook_1(){
            orig=(hook_1_fn)MyHook(fpm(Player::attack),fp(hook_1::onuse));
        }
    } __hook_1;
    uint64_t hook_1::onuse(Player* a0,Actor & a1){
        int res=onEvent_attack(a0,a1);
        if(!res){
            return 0;
        }else{
            return __hook_1.orig(a0,a1);
        }
    }


    typedef int(*hook_2_fn)(Actor* a0,ItemActor & a1);
    static list<void*> ev_pickup;
    void reg_pickup(void* a){
        ev_pickup.push_back(a);
    }
    static int onEvent_pickup(Actor* a0,ItemActor & a1){
        for(auto i:ev_pickup){
            int res=((hook_2_fn)i)(a0,a1);
            if(res==0) return 0;
        }
        return 1;
    }
    static struct hook_2{
        hook_2_fn orig;
        static uint64_t onuse(Actor* a0,ItemActor & a1);
        hook_2(){
            orig=(hook_2_fn)MyHook(fpm(Actor::pickUpItem),fp(hook_2::onuse));
        }
    } __hook_2;
    uint64_t hook_2::onuse(Actor* a0,ItemActor & a1){
        int res=onEvent_pickup(a0,a1);
        if(!res){
            return 0;
        }else{
            return __hook_2.orig(a0,a1);
        }
    }


    typedef int(*hook_3_fn)(GameMode* a0,ItemStack & a1);
    static list<void*> ev_useitem;
    void reg_useitem(void* a){
        ev_useitem.push_back(a);
    }
    static int onEvent_useitem(GameMode* a0,ItemStack & a1){
        for(auto i:ev_useitem){
            int res=((hook_3_fn)i)(a0,a1);
            if(res==0) return 0;
        }
        return 1;
    }
    static struct hook_3{
        hook_3_fn orig;
        static uint64_t onuse(GameMode* a0,ItemStack & a1);
        hook_3(){
            orig=(hook_3_fn)MyHook(fpm(GameMode::useItem),fp(hook_3::onuse));
        }
    } __hook_3;
    uint64_t hook_3::onuse(GameMode* a0,ItemStack & a1){
        int res=onEvent_useitem(a0,a1);
        if(!res){
            return 0;
        }else{
            return __hook_3.orig(a0,a1);
        }
    }


    typedef int(*hook_4_fn)(GameMode* a0,ItemStack & a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5);
    static list<void*> ev_useitemon;
    void reg_useitemon(void* a){
        ev_useitemon.push_back(a);
    }
    static int onEvent_useitemon(GameMode* a0,ItemStack & a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5){
        for(auto i:ev_useitemon){
            int res=((hook_4_fn)i)(a0,a1,a2,a3,a4,a5);
            if(res==0) return 0;
        }
        return 1;
    }
    static struct hook_4{
        hook_4_fn orig;
        static uint64_t onuse(GameMode* a0,ItemStack & a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5);
        hook_4(){
            orig=(hook_4_fn)MyHook(fpm(GameMode::useItemOn),fp(hook_4::onuse));
        }
    } __hook_4;
    uint64_t hook_4::onuse(GameMode* a0,ItemStack & a1,BlockPos const& a2,unsigned char a3,Vec3 const& a4,Block const* a5){
        int res=onEvent_useitemon(a0,a1,a2,a3,a4,a5);
        if(!res){
            return 0;
        }else{
            return __hook_4.orig(a0,a1,a2,a3,a4,a5);
        }
    }


    typedef int(*hook_5_fn)(GameMode* a0,BlockPos const& a1,unsigned char a2);
    static list<void*> ev_build;
    void reg_build(void* a){
        ev_build.push_back(a);
    }
    static int onEvent_build(GameMode* a0,BlockPos const& a1,unsigned char a2){
        for(auto i:ev_build){
            int res=((hook_5_fn)i)(a0,a1,a2);
            if(res==0) return 0;
        }
        return 1;
    }
    static struct hook_5{
        hook_5_fn orig;
        static uint64_t onuse(GameMode* a0,BlockPos const& a1,unsigned char a2);
        hook_5(){
            orig=(hook_5_fn)MyHook(fpm(GameMode::buildBlock),fp(hook_5::onuse));
        }
    } __hook_5;
    uint64_t hook_5::onuse(GameMode* a0,BlockPos const& a1,unsigned char a2){
        int res=onEvent_build(a0,a1,a2);
        if(!res){
            return 0;
        }else{
            return __hook_5.orig(a0,a1,a2);
        }
    }


    typedef int(*hook_6_fn)(GameMode* a0,BlockPos const& a1,unsigned char a2);
    static list<void*> ev_destroy;
    void reg_destroy(void* a){
        ev_destroy.push_back(a);
    }
    static int onEvent_destroy(GameMode* a0,BlockPos const& a1,unsigned char a2){
        for(auto i:ev_destroy){
            int res=((hook_6_fn)i)(a0,a1,a2);
            if(res==0) return 0;
        }
        return 1;
    }
    static struct hook_6{
        hook_6_fn orig;
        static uint64_t onuse(GameMode* a0,BlockPos const& a1,unsigned char a2);
        hook_6(){
            orig=(hook_6_fn)MyHook(fpm(GameMode::destroyBlock),fp(hook_6::onuse));
        }
    } __hook_6;
    uint64_t hook_6::onuse(GameMode* a0,BlockPos const& a1,unsigned char a2){
        int res=onEvent_destroy(a0,a1,a2);
        if(!res){
            return 0;
        }else{
            return __hook_6.orig(a0,a1,a2);
        }
    }


    typedef int(*hook_7_fn)(ServerNetworkHandler* a0,ServerPlayer* a1,bool a2);
    static list<void*> ev_player_left;
    void reg_player_left(void* a){
        ev_player_left.push_back(a);
    }
    static int onEvent_player_left(ServerNetworkHandler* a0,ServerPlayer* a1,bool a2){
        for(auto i:ev_player_left){
            int res=((hook_7_fn)i)(a0,a1,a2);
            if(res==0) return 0;
        }
        return 1;
    }
    static struct hook_7{
        hook_7_fn orig;
        static uint64_t onuse(ServerNetworkHandler* a0,ServerPlayer* a1,bool a2);
        hook_7(){
            orig=(hook_7_fn)MyHook(fpm(ServerNetworkHandler::_onPlayerLeft),fp(hook_7::onuse));
        }
    } __hook_7;
    uint64_t hook_7::onuse(ServerNetworkHandler* a0,ServerPlayer* a1,bool a2){
        int res=onEvent_player_left(a0,a1,a2);
        if(!res){
            return 0;
        }else{
            return __hook_7.orig(a0,a1,a2);
        }
    }


    typedef int(*hook_8_fn)(ServerNetworkHandler* a0,ServerPlayer* a1,NetworkIdentifier* a2);
    static list<void*> ev_player_join;
    void reg_player_join(void* a){
        ev_player_join.push_back(a);
    }
    static int onEvent_player_join(ServerNetworkHandler* a0,ServerPlayer* a1,NetworkIdentifier* a2){
        for(auto i:ev_player_join){
            int res=((hook_8_fn)i)(a0,a1,a2);
            if(res==0) return 0;
        }
        return 1;
    }
    static struct hook_8{
        hook_8_fn orig;
        static uint64_t onuse(ServerNetworkHandler* a0,ServerPlayer* a1,NetworkIdentifier* a2);
        hook_8(){
            orig=(hook_8_fn)MyHook(fpm(ServerNetworkHandler::_sendAdditionalLevelData),fp(hook_8::onuse));
        }
    } __hook_8;
    uint64_t hook_8::onuse(ServerNetworkHandler* a0,ServerPlayer* a1,NetworkIdentifier* a2){
        int res=onEvent_player_join(a0,a1,a2);
        if(!res){
            return 0;
        }else{
            return __hook_8.orig(a0,a1,a2);
        }
    }
*/
list<std::function<bool(ServerPlayer const* a0,string& payload)> > chat_hook;
THook(void*,_ZN20ServerNetworkHandler19_displayGameMessageERK6PlayerRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,void* a,ServerPlayer* sp,string& x){
    int fg=1;
    if(!sp){
        return original(a,sp,x);
    }
    for(auto& hk:chat_hook){
        if(hk(sp,x)==false){
            fg=0;
            break;
        }
    }
    if(fg) return original(a,sp,x);
    return nullptr;
}
void reg_chat(std::function<bool(ServerPlayer const* a0,string& payload)> x){
    chat_hook.push_back(x);
}

list<std::function<void(ServerPlayer *)> > join_hook;
THook(void*,_ZN20ServerNetworkHandler24_sendAdditionalLevelDataER12ServerPlayerRK17NetworkIdentifier,void* a,ServerPlayer* sp,void* x){
    int fg=1;
    for(auto& hk:join_hook){
        hk(sp);
    }
    return original(a,sp,x);
}
void reg_player_join(std::function<void(ServerPlayer *)> x){
    join_hook.push_back(x);
}

list<std::function<void(ServerPlayer *)> > left_hook;
THook(void*,_ZN20ServerNetworkHandler13_onPlayerLeftEP12ServerPlayerb,void* a,ServerPlayer* sp,bool x){
    int fg=1;
    for(auto& hk:left_hook){
        hk(sp);
    }
    return original(a,sp,x);
}
void reg_player_left(std::function<void(ServerPlayer *)> x){
    left_hook.push_back(x);
}


struct Actor;
list<std::function<bool(ServerPlayer* a0,Actor* a1)> > attack_hook;
THook(void*,_ZN6Player6attackER5Actor,ServerPlayer* sp,Actor* x){
    int fg=1;
    for(auto& hk:attack_hook){
        if(hk(sp,x)==false){
            fg=0;
            break;
        }
    }
    if(fg)
    return original(sp,x);
    else return nullptr;
}
void reg_attack(std::function<bool(ServerPlayer* a0,Actor* a1)> x){
    attack_hook.push_back(x);
}

list<std::function<bool(Actor* a0,ItemActor * a1)> > pickup_hook;
THook(void*,_ZN5Actor10pickUpItemER9ItemActor,Actor* sp,ItemActor* x){
    int fg=1;
    for(auto& hk:pickup_hook){
        if(hk(sp,x)==false){
            fg=0;
            break;
        }
    }
    if(fg)
    return original(sp,x);
    else return nullptr;
}
void reg_pickup(std::function<bool(Actor* a0,ItemActor * a1)> x){
    pickup_hook.push_back(x);
}

list<std::function<bool(GameMode* a0,BlockPos const*)> > dest_hook;
THook(void*,_ZN8GameMode12destroyBlockERK8BlockPosh,GameMode* sp,BlockPos const& x,unsigned char cc){
    int fg=1;
    for(auto& hk:dest_hook){
        if(hk(sp,&x)==false){
            fg=0;
            break;
        }
    }
    if(fg)
    return original(sp,x,cc);
    else return nullptr;
}
void reg_destroy(std::function<bool(GameMode* a0,BlockPos const*)> x){
    dest_hook.push_back(x);
}

list<std::function<bool(GameMode* a0,ItemStack * a1,BlockPos const* a2,BlockPos const* dstPos,Block const* a5)> > useion_hook;
THook(void*,_ZN8GameMode9useItemOnER9ItemStackRK8BlockPoshRK4Vec3PK5Block,GameMode* sp,ItemStack& ite, BlockPos const& bpos, unsigned char side, Vec3 const& unk2, Block const* bl){
    int fg=1;
    BlockPos calced(bpos);
    const int Z[]= {0,0,-1,1,0,0};
    const int X[]= {0,0,0,0,-1,1};
    const int Y[]= {-1,1,0,0,0,0};
    calced.x+=X[side];
    calced.y+=Y[side];
    calced.z+=Z[side];
    //printf("side %d\n,%d %d %d\n",side,calced.x,calced.y,calced.z);
    for(auto& hk:useion_hook){
        if(hk(sp,&ite,&bpos,&calced,bl)==false){
            fg=0;
            break;
        }
    }
    if(fg)
    return original(sp,ite,bpos,side,unk2,bl);
    else return nullptr;
}
void reg_useitemon(std::function<bool(GameMode* a0,ItemStack * a1,BlockPos const* a2,BlockPos const* dstPos,Block const* a5)> x){
    useion_hook.push_back(x);
}
list<std::function<bool(ServerPlayer&,BlockPos&)> > popItem_hook;
THook(void*,_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK23ItemFrameDropItemPacket,ServerNetworkHandler* sh,NetworkIdentifier const& iden,Packet* pk){
    ServerPlayer* p=sh->_getServerPlayer(iden,pk->getClientSubId());
    if(p){
        //+0x24
        auto& bpos=access(pk,BlockPos,0x24);
        int fg=1;
        for(auto& i:popItem_hook){
            if(!i(*p,bpos)) fg=0;
        }
        if(fg) return original(sh,iden,pk);
    }
    return nullptr;
}
void reg_popItem(std::function<bool(ServerPlayer&,BlockPos&)> x){
    popItem_hook.push_back(x);
}
using std::function;
list<function<void(Mob&,ActorDamageSource const&)> > mobdie_hook;
void reg_mobdie(function<void(Mob&,ActorDamageSource const&)> x){
    mobdie_hook.push_back(x);
}
THook(void*,_ZN3Mob3dieERK17ActorDamageSource,Mob& th,ActorDamageSource const& src){
    for(auto& i:mobdie_hook){
        i(th,src);
    }
    return original(th,src);
}
list<function<bool(Mob&,ActorDamageSource const&,int&)> > mobhurt_hook;
void reg_mobhurt(function<bool(Mob&,ActorDamageSource const&,int&)> x){
    mobhurt_hook.push_back(x);
}
THook(void*,_ZN3Mob5_hurtERK17ActorDamageSourceibb,Mob& th,ActorDamageSource const& src,int val,bool unk,bool unk2){
    int nprevent=1;
    //printf("call %ld %ld %d\n",th.getUniqueID().id,src.getEntityUniqueID().id,val);
    for(auto& i:mobhurt_hook){
        nprevent&=i(th,src,val);
    }
    return nprevent?original(th,src,val,unk,unk2):nullptr;
}
list<function<bool(Actor&,ActorDamageSource const&,int&)> > actorhurt_hook;
void reg_actorhurt(function<bool(Actor&,ActorDamageSource const&,int&)> x){
    actorhurt_hook.push_back(x);
}
THook(void*,_ZN5Actor4hurtERK17ActorDamageSourceibb,Actor& th,ActorDamageSource const& src,int val,bool unk,bool unk2){
    int nprevent=1;
    for(auto& i:actorhurt_hook){
        nprevent&=i(th,src,val);
    }
    return nprevent?original(th,src,val,unk,unk2):nullptr;
}
list<function<bool(GameMode*,Actor&)> > interact_hook;
void reg_interact(function<bool(GameMode*,Actor&)> x){
    interact_hook.push_back(x);
}
THook(void*,_ZN8GameMode8interactER5ActorRK4Vec3,GameMode* gm,Actor& ac, Vec3 const& vc){
    int nprevent=1;
    for(auto& i:interact_hook){
        nprevent&=i(gm,ac);
    }
    return nprevent?original(gm,ac,vc):nullptr;
}
