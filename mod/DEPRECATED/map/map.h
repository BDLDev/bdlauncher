class ItemStack;
class ActorUniqueID;
class LevelStorage;
class MapItemSavedData{
	char filler[512];
	public:
	MapItemSavedData(ActorUniqueID);
	~MapItemSavedData(){};
	void setLocked();
	void setPixel(unsigned int v, unsigned int x, unsigned int y); //use 0xffrrggbb
	void save(LevelStorage&);
	//Packet* getFullDataPacket() const; //may memory leak
};
/*
class MapItem{
	public:
	static ActorUniqueID getMapId(ItemStack const&);
};
*/
