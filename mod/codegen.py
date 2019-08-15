idxx=0
def codeg(me_name,ev_name,args):
    global idxx
    idxx=idxx+1
    idx=idxx
    base=r'''
    typedef int(*%idx%_fn)(%args%);
    static list<void*> ev_%evn%;
    void reg_%evn%(void* a){
        ev_%evn%.push_back(a);
    }
    static int onEvent_%evn%(%args%){
        for(auto i:ev_%evn%){
            int res=((%idx%_fn)i)(%rarg%);
            if(res==0) return 0;
        }
        return 1;
    }
    static struct %idx%{
        %idx%_fn orig;
        static uint64_t onuse(%args%);
        %idx%(){
            orig=(%idx%_fn)MyHook(fpm(%men%),fp(%idx%::onuse));
        }
    } __%idx%;
    uint64_t %idx%::onuse(%args%){
        int res=onEvent_%evn%(%rarg%);
        if(!res){
            return 0;
        }else{
            return __%idx%.orig(%rarg%);
        }
    }
'''
    idx="hook_%d"%idx
    kksk=[]
    kksk2=[]
    for i in range(len(args)):
        kksk.append("a%d"%i)
        kksk2.append("%s a%d"%(args[i],i))
    rarg=','.join(kksk)
    args=','.join(kksk2)
    base=base.replace(r'%idx%',idx)
    base=base.replace(r'%evn%',ev_name)
    base=base.replace(r'%men%',me_name)
    base=base.replace(r'%args%',args)
    base=base.replace(r'%rarg%',rarg)
    print(base)
codeg('Player::attack','attack',('Player*','Actor &'))
codeg('Actor::pickUpItem','pickup',('Actor*','ItemActor &'))
codeg('GameMode::useItem','useitem',('GameMode*','ItemStack &'))
codeg('GameMode::useItemOn','useitemon',('GameMode*','ItemStack &','BlockPos const&','unsigned char','Vec3 const&','Block const*'))
codeg('GameMode::buildBlock','build',('GameMode*','BlockPos const&','unsigned char'))
codeg('GameMode::destroyBlock','destroy',('GameMode*','BlockPos const&','unsigned char'))
