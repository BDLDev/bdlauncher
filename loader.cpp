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
    void* handle=dlopen(fplug.c_str(),RTLD_NOW|RTLD_GLOBAL);
    if(handle==nullptr) {
        printf("[MOD] err loading %s handle %p %s\n",fplug.c_str(),handle,dlerror());
        exit(1);
    }
    char buf[100];
    int fsz=fplug.size();
    char fpp[100];
    strcpy(fpp,fplug.c_str());
    fpp[fsz-3]=0;
    sprintf(buf,"%s_init",fpp+7);
    printf("enabling %s entry %s\n",fplug.c_str(),buf);
    void* init=dlsym(handle,buf);
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
        modlist.push_back(std::string(str));
    }
    ret_list=modlist;
    printf("[MOD] start loading\n");
    load_helper(modlist);
    return ret_list;
}
