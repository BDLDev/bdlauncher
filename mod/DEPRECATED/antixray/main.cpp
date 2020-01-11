#include<MC.h>
#include<Loader.h>
#include"minecraft/core/types.h"
#include"../base/base.h"

extern "C" {
  __attribute__((visibility("default"))) void antixray_init(std::list<std::string>& modlist);
}
extern void load_helper(std::list<std::string>& modlist);
static const unordered_set<short> ores={14,15,16,21,54,56,73,74,129,153};
bool isOre(short x){
    return ores.count(x);
}
bool canObfs(short x){
    const short obfs[]={1,12,24};
    for(auto i : obfs){
        if(x==i) return true;
    }
    return false;
}

#define OBFS_RATIO 53
int wtfmagic=time(0)%OBFS_RATIO;
void reCalcChunk(shared_ptr<LevelChunk> chunk,unordered_set<int>& l){
    short ids[66][18][18];
    memset(ids,0xff,sizeof(ids));
    //x 1 to 16 y 1 to 64 
    for(int k=1;k<=64;++k)
    for(int i=0;i<16;++i)
    for(int j=0;j<16;++j){
        ids[k][i+1][j+1]=chunk->getBlock({(unsigned char)i,(short)k,(unsigned char)j})->getLegacyBlock()->getBlockItemId();
    }
    for(int k=1;k<=64;++k)
    for(int i=1;i<=16;++i)
    for(int j=1;j<=16;++j){
        if(isOre(ids[k][i][j])){
            int fg=ids[k+1][i][j]==0 || ids[k-1][i][j]==0 || ids[k][i+1][j]==0 || ids[k][i-1][j]==0 || ids[k][i][j+1]==0 || ids[k][i][j-1]==0;
            if(!fg){
                ChunkBlockPos pos(i-1,k,j-1);
                l.insert(*((int*)&pos)); //x,z,y
            }
        } 
    }
}



//unordered_map<unsigned long,unordered_set<int> > anti_cache;
list<std::pair<unsigned long,unordered_set<int>* > > anti_cache;
unordered_set<int>* cache_fetch(unsigned long hash){
    for(auto i=anti_cache.begin();i!=anti_cache.end();++i){
        if(i->first==hash){
            std::swap(*anti_cache.begin(),*i);
            return anti_cache.begin()->second;
        }
    }
    return nullptr;
}
void cache_push(unsigned long hash,unordered_set<int>* v){
    anti_cache.push_front(std::make_pair(hash,v));
    if(anti_cache.size()>=128) {auto x=anti_cache.back().second; delete x; anti_cache.pop_back();}
}
void calcChunk(shared_ptr<LevelChunk> chunk,ChunkPos& cpos,NetworkChunkPublisher& thi,list<std::pair<int,Block*> >&undolist){
    auto hash=chunk->getPosition()->hash();
    unordered_set<int>* Pores=cache_fetch(hash);
    if(!Pores){
        unordered_set<int>* ore_list=new unordered_set<int>();
        reCalcChunk(chunk,*ore_list);
        cache_push(hash,ore_list);
        Pores=ore_list;
    }
    unordered_set<int>& ores=*Pores;
    Block* air=chunk->getBlock({0,500,0});
    int tmp=*ores.begin();
    Block* obfs_blk=chunk->getBlock(fcast(ChunkBlockPos,tmp));
    for(int k=28;k<=54;++k)
    for(int i=0;i<16;++i)
    for(int j=0;j<16;++j){
        ChunkBlockPos poss(i,k,j);
        int pos_hash=*(int*)&poss;
        if(pos_hash%OBFS_RATIO==wtfmagic){
            auto x=chunk->getBlock(poss);
            if(canObfs(x->getLegacyBlock()->getBlockItemId())){
                undolist.push_back({pos_hash,x});
                chunk->setBlock2(poss,*obfs_blk);
            }
        }
    }
    for(auto i:ores){
        undolist.push_back(std::make_pair(i,chunk->getBlock(fcast(ChunkBlockPos,i))));
        chunk->setBlock2(fcast(ChunkBlockPos,i),*air);
    }
}

void undoChunk(shared_ptr<LevelChunk> chunk,list<std::pair<int,Block*> >& ores){
    for(auto& i:ores){
        chunk->setBlock2(fcast(ChunkBlockPos,i.first),*i.second);
    }
}
THook(int,_ZN21NetworkChunkPublisher16_sendQueuedChunkERK8ChunkPosPN15ClientBlobCache6Server15TransferBuilderE,NetworkChunkPublisher* thi,ChunkPos* pos,ClientBlobCache::Server::TransferBuilder* unk){
    if(!unk) {printf("wtf refused it\n");return 0;} //refuse no cache client
    auto& x=thi->getSource();
    if(x){
        ChunkViewSource* src=x.get();
        //void(*fn)(shared_ptr<LevelChunk>*,ChunkViewSource*,ChunkPos&);
        //fn=(typeof(fn))(*((*(long**)src)+4));
        shared_ptr<LevelChunk> cunk;
        //fn(&cunk,src,*pos);
	(*(void ( **)(void*,void*,void*))(*(unsigned long *)src + 32LL))(&cunk,src,pos);
        if(cunk){
            if(cunk->getState().load().val==8 && (cunk)->isOwnedByTickingThread()==1){
                auto pos=(cunk)->getPosition();
                list<std::pair<int,Block*> > undo;
                calcChunk(cunk,*pos,*thi,undo);
                auto ret=original(thi,pos,unk);
                undoChunk(cunk,undo);
                return ret;
            }
        }
    }
    return 0;
}
void removeOre(int x,int y,int z){
    ChunkPos pos={x>>4,z>>4};
    auto it=cache_fetch(pos.hash());
    if(it!=nullptr){
        ChunkBlockPos poss(x&0xf,y&0xff,z&0xf);
        it->erase(fcast(int,poss));
    }
}
void flashBlock(int x,int y,int z,BlockSource* reg,Dimension* dim){
    if(y<0) return;
    auto blk=reg->getBlock({x,y,z});
    int resend=0;
    if(isOre(blk->getLegacyBlock()->getBlockItemId())){
        removeOre(x,y,z);
        resend=1;
    }
    if(!resend){
        ChunkBlockPos pos(x&0xf,y,z&0xf);
        if(fcast(int,pos)%OBFS_RATIO==wtfmagic) resend=1;
    }
    if(resend){
        MyPkt pk(21,[&](void* pk,BinaryStream& bs)->void{
                        bs.writeVarInt(x);
                        bs.writeUnsignedVarInt(y);
                        bs.writeVarInt(z);
                        bs.writeUnsignedVarInt(blk->getRuntimeId());
                        bs.writeUnsignedVarInt(0);
                        bs.writeUnsignedVarInt(0);
                    });
                    dim->sendPacketForPosition({x,y,z},*(Packet*)&pk,nullptr);
    }
}
int onDestBlock(GameMode* a0,BlockPos const& pos,unsigned char a2){
    auto reg=&a0->player->getRegion();
    auto dim=&a0->player->getDimension();
    int x=pos.x,y=pos.y,z=pos.z;
    flashBlock(x+1,y,z,reg,dim);
    flashBlock(x-1,y,z,reg,dim);
    flashBlock(x,y+1,z,reg,dim);
    flashBlock(x,y-1,z,reg,dim);
    flashBlock(x,y,z+1,reg,dim);
    flashBlock(x,y,z-1,reg,dim);
    return 1;
}
void antixray_init(std::list<std::string>& modlist) {
  reg_destroy((void*)(onDestBlock));
  printf("[AntiXray] Loaded!\n");
  load_helper(modlist);
}
