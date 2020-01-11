#pragma once
#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <memory>
#include <list>
#include <atomic>
#include <vector>
#include <cstdint>
#include <cstring>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string_view>

#define BDL_EXPORT __attribute__((visibility("default")))

using std::list;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::unordered_map;
using std::unordered_set;
using std::string_view;
#define access(ptr, type, off) (*((type *)(((uintptr_t)ptr) + off)))
#define fcast(type, x) (*((type *)&x))
#ifndef fp
#define fp(x) ((void *)(x))
#endif
struct BlockPos;
class Vec3
{
public:
    float x, y, z;
    Vec3(){};
    Vec3(float x, float y, float z)
        : x(x), y(y), z(z) {}
    Vec3(BlockPos const &);
    inline float L2dist(const Vec3 &a) const
    {
        return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) + (z - a.z) * (z - a.z);
    }
    inline float L2distxz(const Vec3 &a) const
    {
        return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) * 0.01 + (z - a.z) * (z - a.z);
    }
};
typedef unsigned long STRING_HASH;

constexpr STRING_HASH do_hash(string_view x){
    auto sz=x.size();
    auto c=x.data();
    unsigned int hash1=0;unsigned int hash2=0;
    for(int i=0;i<sz;++i){
        hash1=(hash1*47+c[i])%1000000007;
        hash2=(hash2*83+c[i])%1000000009;
    }
    return (((STRING_HASH)hash1)<<32)|hash2;
}

extern "C"
{
    void _ZN6PacketC2Ev(void *);
    void _ZN16BinaryDataOutputC2ER12BinaryStream(void *, void *);
    void _ZN25ActorDefinitionIdentifierD2Ev(void*);
    void _ZTV12ServerPlayer(void); //dummy
}

typedef void *UNK_64;
class ServerPlayer;
//utils for runtime type detecting
static auto vtSP = ((void**)_ZTV12ServerPlayer)+2;//((void **)dlsym(NULL, "_ZTV12ServerPlayer") + 2);
template <class T>
inline ServerPlayer *getSP(T &a)
{
    return access(&a, void *, 0) == vtSP ? (ServerPlayer *)&a : nullptr;
}
template <class T>
inline ServerPlayer *getSP(T *a)
{
    if (!a)
        return nullptr;
    return access(a, void *, 0) == vtSP ? (ServerPlayer *)a : nullptr;
}


class Player;
class BinaryStream
{
    char filler[312];

public:
    BinaryStream();
    BinaryStream(string &, bool);
    UNK_64 writeFloat(float);
    UNK_64 writeDouble(double);
    UNK_64 writeStream(BinaryStream &);
    UNK_64 writeVarInt(int);
    UNK_64 writeVarInt64(long);
    UNK_64 writeSignedInt(int);
    UNK_64 writeFixedFloat(float, double);
    UNK_64 writeSignedInt64(long);
    UNK_64 writeSignedShort(short);
    UNK_64 writeUnsignedInt(unsigned int);
    string getAndReleaseData();
    UNK_64 writeUnsignedChar(unsigned char);
    UNK_64 writeUnsignedInt64(unsigned long);
    UNK_64 writeUnsignedShort(unsigned short);
    UNK_64 writeUnsignedVarInt(unsigned int);
    UNK_64 writeNormalizedFloat(float);
    UNK_64 writeUnsignedVarInt64(unsigned long);
    UNK_64 writeSignedBigEndianInt(int);
    UNK_64 reset();
    UNK_64 write(void const *, unsigned long);
    UNK_64 reserve(unsigned long);
    UNK_64 writeBool(bool);
    UNK_64 writeByte(unsigned char);
    void writeStr(string_view sv){
        writeUnsignedVarInt(sv.size());
        write(sv.data(),sv.size());
    }
    void writeVec3(const Vec3& vc){
        writeFloat(vc.x);writeFloat(vc.y);writeFloat(vc.z);
    }
};
struct LevelStorage;
struct ServerPlayer;
struct MapItemSavedData;
struct ItemStack;
struct ItemActor;
struct CommandContext;
enum class MCCATEGORY : char
{
};
struct ActorUniqueID
{
    unsigned long id;
    ActorUniqueID(){
        id=-1;
    }
};
typedef uint64_t u64;
struct MCRESULT
{
    bool success;        // 0
    MCCATEGORY category; // 1
    unsigned short code; // 2

    static bool isSuccess(int);

    MCRESULT(bool, MCCATEGORY, unsigned short);
    MCRESULT(int);

    bool operator==(MCRESULT const &) const;
    bool operator!=(MCRESULT const &) const;

    int getFullCode() const;
    bool isSuccess() const;
};
struct CommandOrigin;
struct CompoundTag;
class MinecraftCommands
{
public:
    MCRESULT requestCommandExecution(std::unique_ptr<CommandOrigin>, std::string const &, int, bool) const;
};
class Actor;
struct Level
{
    void *getPacketSender() const;
    UNK_64 save();
    ServerPlayer *getPlayer(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &) const;
    LevelStorage *getLevelStorage();
    void forEachPlayer(std::function<bool(Player &)>);
    MapItemSavedData &getMapSavedData(std::unique_ptr<CompoundTag, std::default_delete<CompoundTag>> const &);
    int getUserCount() const;
    int getTickedMobCountPrevious() const;
    std::vector<std::unique_ptr<ServerPlayer>> *getUsers();
    Actor *fetchEntity(ActorUniqueID, bool) const;
};
struct ChunkBlockPos
{
    unsigned char x, z;
    short y;
    ChunkBlockPos(unsigned char a, short b, unsigned char c)
    {
        x = a, z = c;
        y = b;
    };
};
struct BlockPos;
struct BlockActor
{
    BlockPos &getPosition() const;
};
struct BlockProperty
{
    unsigned long x;
};
struct BlockLegacy
{
public:
    short getBlockItemId() const;
    void addBlockProperty(BlockProperty);
};
struct Block
{
public:
    float getDestroySpeed() const;
    BlockLegacy *getLegacyBlock() const;
    bool isSolid() const;
    bool isContainerBlock() const;
    unsigned int &getRuntimeId() const;
};
struct ChunkState
{
    char val;
};
struct ChunkPos
{
    int x, z;
    unsigned long hash()
    {
        return *((unsigned long *)this);
    }
};
struct BlockPos;

struct BlockPos
{
public:
    int x, y, z;
    BlockPos();
    BlockPos(int x, int y, int z)
        : x(x), y(y), z(z) {}
    BlockPos(Vec3 const &);
    BlockPos(BlockPos const &p)
        : x(p.x), y(p.y), z(p.z) {}
    bool operator==(BlockPos const &pos) const
    {
        if (this->x != pos.x)
            return false;
        if (this->y != pos.y)
            return false;
        if (this->z != pos.z)
            return false;
        return true;
    }
    bool operator!=(BlockPos const &pos) const
    {
        return !(*this == pos);
    }
};
struct BlockSource
{
public:
    Block *getBlock(BlockPos const &) const;
    Block *getBlock(int, int, int) const;
    void setBlockNoUpdate(int, int, int, Block const &);
    void setBlock(int, int, int, Block const &, int);
    UNK_64 clearCachedLastChunk();
    UNK_64 clearDeletedEntities();
};
struct LevelChunk
{
    ChunkPos *getPosition() const;
    char isOwnedByTickingThread() const;
    std::atomic<ChunkState> &getState() const;
    Block *getBlock(ChunkBlockPos const &) const;
    void setBlock(ChunkBlockPos const &, Block const &, BlockSource *, std::shared_ptr<BlockActor>);
    void setBlock2(ChunkBlockPos const &pos, Block const &blk)
    {
        this->setBlock(pos, blk, nullptr, {nullptr});
    }
};
struct ChunkViewSource;
class ServerPlayer;
class NetworkIdentifier;
struct ServerNetworkHandler
{
    ServerPlayer *_getServerPlayer(NetworkIdentifier const &, unsigned char);
    void _onPlayerLeft(ServerPlayer *, bool);
    void _sendAdditionalLevelData(ServerPlayer &, NetworkIdentifier const &);
    void disconnectClient(NetworkIdentifier const &, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &, bool); //def false?
    void onSubclientLogoff(NetworkIdentifier const &, unsigned char const &);
};
struct Minecraft
{
    ServerNetworkHandler *getNetworkHandler();
    ServerNetworkHandler *getNetEventCallback();
    MinecraftCommands *getCommands();
    Level *getLevel() const;
    UNK_64 disconnectClient(NetworkIdentifier const &, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &);
};
struct ClientBlobCache
{
    struct Server
    {
        struct TransferBuilder;
    };
};
struct BinaryDataOutput;
struct NetworkChunkPublisher
{
    void sendpk(void *pk)
    {
        void *v17 = (*((Level **)this + 1))->getPacketSender();
        (*(void (**)(void *, char *, void *, long))(*(long *)v17 + 32LL))(
            v17,
            (char *)this + 24,
            pk,
            *((unsigned char *)this + 184));
    }
    std::unique_ptr<ChunkViewSource> &getSource() { return *(unique_ptr<ChunkViewSource> *)((char *)this + 216); }
    /*ServerPlayer* getPlayer(){
	    return getMC()->getNetworkHandler()->_getServerPlayer(*(NetworkIdentifier*)((char *)this + 24),*((unsigned char *)this + 184));
	}*/
    //void _serializeAndCache(LevelChunkPacket&, ClientBlobCache::Server::TransferBuilder&, std::function<void (BinaryDataOutput&)>&&);
};
class IDataOutput
{
public:
    inline void writeb(void const *c, unsigned long s)
    {
        auto vtbl = (*(char **)this);
        vtbl += 80;
        void (*fn)(void *, void const *, unsigned long);
        fn = ((typeof(fn)) * (void **)vtbl);
        fn(this, c, s);
    }
};
class IDataInput
{
};
class BinaryDataOutput : public IDataOutput
{
    char filler[512];

public:
    BinaryDataOutput(BinaryStream &x)
    {
        _ZN16BinaryDataOutputC2ER12BinaryStream(this, &x);
    }
    void writeByte(char);
};
struct ReadOnlyBinaryStream
{
    char filler[256];
    ReadOnlyBinaryStream(string *x)
    {
        auto fn = dlsym(NULL, "_ZN20ReadOnlyBinaryStreamC2EONSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE");
        void (*fnn)(void *, string *);
        fnn = (typeof(fnn))fn;
        fnn(this, x);
    }
};
class BinaryDataInput : public IDataInput
{
    char filler[256];

public:
    BinaryDataInput(ReadOnlyBinaryStream &x)
    {
        auto fn = dlsym(NULL, "_ZN15BinaryDataInputC2ER20ReadOnlyBinaryStream");
        void (*fnn)(void *, void *);
        fnn = (typeof(fnn))fn;
        fnn(this, &x);
    }
};
struct CompoundTag
{
    Vec3 getVec3(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &) const;
    void putVec3(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &, Vec3);
    float getFloatTag(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &);
    int64_t getInt64Tag(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &);
    short getShortTag(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &);
    UNK_64 putFloat(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, float);
    UNK_64 putInt64(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, long);
    UNK_64 putShort(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, short);
    unsigned long int hash() const;
    string toString() const;
};
struct NbtIo
{
    static unique_ptr<CompoundTag> &read(IDataInput &);
    static void write(CompoundTag const *, IDataOutput &);
};
struct PlayerStorageIds
{
    string unk;
    string unk1;
    string unk2;
    string unk3;
    string id;
    string unk5;
};



struct ItemStackBase
{
    char filler[312]; //unk
    short getAuxValue() const;
    void setAuxValue(short);
    short getId() const;
    BlockLegacy const &getLegacyBlock() const;
    unsigned char getStackSize() const;
    bool isBlock() const;
    const std::string toString() const;
    bool isEnchanted() const;
    bool isOffhandItem() const;
    unsigned int getIdAuxEnchanted() const;
    bool isNull() const;
    std::unique_ptr<CompoundTag, std::default_delete<CompoundTag>> &getUserData() const;
    void setStackSize(unsigned char);
    void setCustomLore(std::vector<string> const&);
    void setCustomName(string const&);
};
extern "C"{
    void _ZN9ItemStackD0Ev(void*);
    void _ZN9ItemStackD2Ev(void*);
}
struct Item;
struct ItemStack : ItemStackBase
{
    char filler[312];
    ItemStack(){
    } //override
    ItemStack(Item const&);
    ItemStack(ItemStack const&);
    void defunct_cfree(){
        _ZN9ItemStackD0Ev(this);
    }
    ~ItemStack(){
        _ZN9ItemStackD2Ev(this);
    }
};
struct InventorySource;
struct InventoryAction
{
    char filler[288];
    InventorySource &getSource(void) const;
    ItemStack *getToItem(void) const;
    ItemStack *getFromItem(void) const;
    unsigned int getSlot(void) const;
};
struct InventoryTransactionManager
{
    char filler[40];
    Player *getPlayer() const
    {
        return *(Player **)this;
    }
    void _createServerSideAction(ItemStack const&, ItemStack const&);
};
struct InventorySource
{
    char filler[12];
    int getType() const;
    int getFlags() const;
    int getContainerId() const;
    string toStr() const
    {
        return std::to_string(getType()) + ":" + std::to_string(getFlags()) + ":" + std::to_string(getContainerId());
    }
};

struct ServerPlayer;
struct Player;
struct Actor;
struct GameMode
{
public:
    void *vtbl;
    ServerPlayer *player;
    ServerPlayer *getPlayer()
    {
        return player;
    }
    u64 attack(Actor &);
    u64 buildBlock(BlockPos const &, unsigned char);
    u64 destroyBlock(BlockPos const &, unsigned char);
    u64 useItem(ItemStack &);
    u64 useItemOn(ItemStack &, BlockPos const &, unsigned char, Vec3 const &, Block const *);
};
struct Packet
{
    unsigned char getClientSubId() const;
};

class Vec3;
class MobEffect;
struct MobEffectInstance
{
    unsigned int getId() const;
};
class ItemStack;
struct Dimension
{
    void forEachPlayer(std::function<bool(Player &)>);
    int getId() const;
    void sendPacketForPosition(BlockPos const &, Packet const &, Player const *);
};
class TickingArea
{
public:
    BlockSource *getBlockSource();
};
class Mob;
typedef unsigned long Shash_t;
enum ArmorSlot:int{
    UNK=0
};
struct SynchedActorData{
    template<typename T>
	void set(unsigned short, T const&);
};
class Actor : public TickingArea
{
public:
    const std::string &getNameTag() const;
    Shash_t getNameTagAsHash(){
        return do_hash(getNameTag());
    } //fix it
    Vec3 const &getPos() const;
    bool isRiding() const;
    std::vector<MobEffect> &getAllEffects() const;
    int getDimensionId() const;
    BlockSource &getRegion() const;
    ItemStack &getOffhandSlot() const;
    Dimension &getDimension() const;
    long getRuntimeID() const;
    ActorUniqueID &getUniqueID() const;
    void setPos(const Vec3 &);
    u64 pickUpItem(ItemActor &);
    void kill();
    void setNameTag(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &);
    void setScoreTag(string const&);
    Mob *getOwner() const;
    ServerPlayer *getPlayerOwner() const;
    int getEntityTypeId() const;
    int getOwnerEntityType();
    ActorUniqueID getOwnerId() const;
    void setNameTagVisible(bool);
    void setNameTagAlwaysVisible(){
        getDATA()->set(80,(signed char)1);
    }
    bool isPlayer() const
    {
        return access(this, void *, 0) == ((void **)vtSP);
    }
    void setSize(float scale, float bbox){
        getDATA()->set(38,scale);
        getDATA()->set(53,bbox);
        getDATA()->set(54,bbox);
    }
    void setArmor(ArmorSlot, ItemStack const&);
    void setCarriedItem(ItemStack const&);
    void setAutonomous(bool);
    inline SynchedActorData* getDATA(){
        return (SynchedActorData*)(((uintptr_t)this)+0x130);
    }
};
class Mob : public Actor
{
public:
    float getYHeadRot() const;
    bool isGliding() const;
    bool isJumping() const;
    void kill();
};
class Certificate;
class ExtendedCertificate
{
public:
    static std::string getXuid(Certificate const &);
    static std::string getIdentityName(Certificate const &);
};
enum struct AbilitiesIndex : int
{
    MAY_FLY = 10
};
enum struct ContainerID:unsigned long{
    DEFAULT=0
};
struct PlayerInventoryProxy{
    ItemStack& getItem(int, ContainerID) const;
    int getContainerSize(ContainerID) const;
    void add(ItemStack&, bool);
    void setItem(int, ItemStack const&, ContainerID);
    void clearSlot(int, ContainerID);
    bool removeResource(ItemStack const&);
};
struct FillingContainer{
    int getContainerSize() const;
    ItemStack& getItem(int) const;
};
class Player : public Mob
{
private:
public:
    bool isPlayerInitialized() const;
    int getCommandPermissionLevel() const;
    Certificate &getCertificate() const;
    bool canUseAbility(AbilitiesIndex) const;
    inline const std::string& getName() const
    {
        return getNameTag();
        //return getRealNameTag();
    }
    std::string getRealNameTag() const
    {
        return ExtendedCertificate::getIdentityName(getCertificate());
    }
    unsigned char getPlayerPermissionLevel() const;
    ItemStack &getCarriedItem() const;
    std::string getXUID() const { return ExtendedCertificate::getXuid(getCertificate()); }
    uint64_t attack(Actor &);
    bool isCreative(void) const;
    unsigned char getClientSubId() const;
    PlayerInventoryProxy& getSupplies() const;
    FillingContainer* getEnderChestContainer();
    void setName(std::string const&);
    InventoryTransactionManager* getTransactionManager();
    void updateInventoryTransactions();
};
void base_sendPkt(class ServerPlayer* sp,Packet& pk);
class ServerPlayer : public Player
{
public:
    void disconnect();
    //void sendNetworkPacket(Packet &) const;
    void sendNetworkPacket(Packet& pk){
        //base required
        base_sendPkt(this,pk);
    }
    void sendInventory(bool);
};


struct MyPkt : Packet
{
    void **vtbl;
    char filler[256];
    int id;
    std::function<void(void *, BinaryStream &)> realexe;
    static int dummy() { return 0; }
    static int getId(MyPkt &th) { return th.id; }
    static void execute_wr(MyPkt &th, BinaryStream &x) { th.realexe(&th, x); }
    const void *vtbls[7] = {
        fp(MyPkt::dummy),
        fp(MyPkt::dummy),
        fp(MyPkt::getId),
        fp(MyPkt::dummy), //ret string
        fp(MyPkt::execute_wr),
        fp(MyPkt::dummy),
        fp(MyPkt::dummy) //disallow batch
    };
    void ParentInit()
    {
        _ZN6PacketC2Ev(this);
    }
    MyPkt(int idx, std::function<void(void *, BinaryStream &)> callb)
    {
        ParentInit();
        id = idx;
        vtbl = (void **)vtbls;
        realexe = callb;
    }
    MyPkt(int idx)
    {
        ParentInit();
        vtbl = (void **)vtbls;
        id = idx;
    }
};
struct TextPacket : Packet
{
    char filler[312];
    virtual ~TextPacket();
    static TextPacket createTranslatedAnnouncement(std::string const &sender, std::string const &content, std::string const &uuid, std::string const &xuid);
    static TextPacket createRaw(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const &);
    static TextPacket createTranslatedChat(std::string const &txt);
    static TextPacket createJukeboxPopup(std::string const &txt);
};

class ActorDamageSource
{
public:
    virtual void destruct1() = 0;
    virtual void destruct2() = 0;
    virtual bool isEntitySource() const = 0;
    virtual bool isChildEntitySource() const = 0;

private:
    virtual UNK_64 unk1() = 0;
    virtual UNK_64 unk2() = 0;
    virtual UNK_64 unk3() = 0;
    virtual UNK_64 unk4() = 0;

public:
    virtual ActorUniqueID getEntityUniqueID() const = 0;
    virtual int getEntityType() const = 0;
    virtual int getEntityCategories() const = 0;
};

struct LoopbackPacketSender{
    void sendBroadcast(Packet const&);
    void sendToClient(NetworkIdentifier const&, Packet const&, unsigned char);
};
struct Item{
};
struct ItemRegistry{
};
struct ActorDefinitionIdentifier{
    char filler[sizeof(string)*5];
    ActorDefinitionIdentifier(string const&);
    ~ActorDefinitionIdentifier(){
        _ZN25ActorDefinitionIdentifierD2Ev(this);
    }
};
struct CommandUtils{
    static void spawnEntityAt(BlockSource&, Vec3 const&, ActorDefinitionIdentifier const&, ActorUniqueID&, Actor* unk=nullptr);
};

