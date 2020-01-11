static_deque<bool(*)(ServerPlayer* a0,string& payload)> chat_hook;
THook(void*,_ZN20ServerNetworkHandler19_displayGameMessageERK6PlayerRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,void* a,ServerPlayer* sp,string& x){
    int fg=1;
    if(!sp){
        return original(a,sp,x);
    }
    for(auto& hk:chat_hook){
        if(hk(sp,x)==false){
            fg=0;
        }
    }
    if(fg) return original(a,sp,x);
    return nullptr;
}
static_deque<void(*)(ServerPlayer *)> join_hook;
THook(void*,_ZN12ServerPlayer27setLocalPlayerAsInitializedEv,ServerPlayer* sp){
    for(auto& hk:join_hook){
        hk(sp);
    }
    return original(sp);
}
static_deque<void(*)(ServerPlayer *)>  left_hook;
THook(void*,_ZN20ServerNetworkHandler13_onPlayerLeftEP12ServerPlayerb,void* a,ServerPlayer* sp,bool x){
    for(auto& hk:left_hook){
        hk(sp);
    }
    return original(a,sp,x);
}


struct Actor;
static_deque<bool(*)(ServerPlayer* a0,Actor* a1)> attack_hook;
THook(void*,_ZN6Player6attackER5Actor,ServerPlayer* sp,Actor* x){
    int fg=1;
    for(auto& hk:attack_hook){
        if(hk(sp,x)==false){
            fg=0;
        }
    }
    if(fg)
    return original(sp,x);
    else return nullptr;
}


static_deque<bool(*)(Actor* a0,ItemActor * a1)> pickup_hook;
THook(void*,_ZN5Actor10pickUpItemER9ItemActor,Actor* sp,ItemActor* x){
    int fg=1;
    for(auto& hk:pickup_hook){
        if(hk(sp,x)==false){
            fg=0;
        }
    }
    if(fg)
    return original(sp,x);
    else return nullptr;
}


static_deque<bool(*)(GameMode* a0,BlockPos const*)> dest_hook;
THook(void*,_ZN8GameMode12destroyBlockERK8BlockPosh,GameMode* sp,BlockPos const& x,unsigned char cc){
    int fg=1;
    for(auto& hk:dest_hook){
        if(hk(sp,&x)==false){
            fg=0;
        }
    }
    if(fg)
    return original(sp,x,cc);
    else return nullptr;
}

static_deque<bool(*)(GameMode* a0,ItemStack * a1,BlockPos const* a2,BlockPos const* dstPos,Block const* a5)> useion_hook;
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
        }
    }
    if(fg)
    return original(sp,ite,bpos,side,unk2,bl);
    else return nullptr;
}


static_deque<bool(*)(ServerPlayer&,BlockPos&)> popItem_hook;
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

static_deque<void(*)(Mob&,ActorDamageSource const&)> mobdie_hook;


THook(void*,_ZN3Mob3dieERK17ActorDamageSource,Mob& th,ActorDamageSource const& src){
    for(auto& i:mobdie_hook){
        i(th,src);
    }
    return original(th,src);
}
static_deque<bool(*)(Mob&,ActorDamageSource const&,int&)> mobhurt_hook;


THook(void*,_ZN3Mob5_hurtERK17ActorDamageSourceibb,Mob& th,ActorDamageSource const& src,int val,bool unk,bool unk2){
    int nprevent=1;
    //printf("call %ld %ld %d\n",th.getUniqueID().id,src.getEntityUniqueID().id,val);
    for(auto& i:mobhurt_hook){
        nprevent&=i(th,src,val);
    }
    return nprevent?original(th,src,val,unk,unk2):nullptr;
}
static_deque<bool(*)(Actor&,ActorDamageSource const&,int&)> actorhurt_hook;


THook(void*,_ZN5Actor4hurtERK17ActorDamageSourceibb,Actor& th,ActorDamageSource const& src,int val,bool unk,bool unk2){
    int nprevent=1;
    for(auto& i:actorhurt_hook){
        nprevent&=i(th,src,val);
    }
    return nprevent?original(th,src,val,unk,unk2):nullptr;
}
static_deque<bool(*)(GameMode*,Actor&)> interact_hook;

THook(void*,_ZN8GameMode8interactER5ActorRK4Vec3,GameMode* gm,Actor& ac, Vec3 const& vc){
    int nprevent=1;
    for(auto& i:interact_hook){
        nprevent&=i(gm,ac);
    }
    return nprevent?original(gm,ac,vc):nullptr;
}
#define regAPI(name,hk) BDL_EXPORT void reg_##name(decltype(&(***hk##_hook.begin())) x){hk##_hook.push_back(x);}
regAPI(chat,chat)
regAPI(player_join,join)
regAPI(player_left,left)
regAPI(attack,attack)
regAPI(pickup,pickup)
regAPI(destroy,dest)
regAPI(useitemon,useion)
regAPI(popItem,popItem)
regAPI(mobdie,mobdie)
regAPI(mobhurt,mobhurt)
regAPI(actorhurt,actorhurt)
regAPI(interact,interact)