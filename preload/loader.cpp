#include"mods.h"
void load_helper(std::list<std::string>& modlist) {
    if(modlist.size()==0) return;
    std::string fplug;
    while(fplug.size()==0 && !modlist.empty()) {
        const std::string& item=modlist.front();
        fplug=(item[item.size()-1]=='\r')?item.substr(0,item.size()-1):item;
        modlist.pop_front();
    }
    if(fplug.size()==0) return;
    void* handle=dlopen(fplug.c_str(),RTLD_NOW|RTLD_GLOBAL|RTLD_DEEPBIND);
    if(handle==nullptr) {
        printf("[MOD] err loading %s handle %p %s\n",fplug.c_str(),handle,dlerror());
        exit(1);
    }
    printf("enabling %s\n",fplug.c_str());
    void* init=dlsym(handle,"mod_init");
    if(init==nullptr) {
        printf("[MOD] err loading %s handle %p %s\n",fplug.c_str(),handle,dlerror());
        exit(1);
    }
    ((typeof(&load_helper))init)(modlist);
}

static void cook(char* a) {
    while(*a!=0) {
        if(*a=='\n') {
            *a=0;
            return;
        }
        a++;
    }
}
std::list<std::string> mod_loadall() {
    std::list<std::string> modlist,ret_list;
    FILE* fp=fopen("mods/mod.list","r");
    if(fp==nullptr) {
        perror("[MOD] cannot open mods/mod.list\n");
        exit(1);
    }
    char str[108];
    strcpy(str,"./mods/");
    while(fgets(str+7,100,fp)!=nullptr) {
        cook(str);
        printf("[MOD] loading %s\n",str);
        modlist.emplace_back(std::string(str));
    }
    ret_list=modlist;
    printf("[MOD] start loading\n");
    load_helper(modlist);
    return ret_list;
}
