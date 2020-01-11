#pragma once
//!!!DEPRECATED
#include<cstdlib>
#include <string>
#include<cstring>
#include<cstdio>
#include<iterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using std::string;
template<typename T>
static auto autosize(const T& a){
    return std::distance(a.begin(),a.end());
}
static void putint(char* buf,int& ptr,int v){
    memcpy(buf+ptr,&v,sizeof(v));
    ptr+=sizeof(v);
}
static void putstr(char* buf,int& ptr,const string& v){
    int sz=v.size();
    putint(buf,ptr,sz);
    memcpy(buf+ptr,v.c_str(),sz);
    ptr+=sz;
}
static void getint(const char* buf,int& ptr,int& v){
    memcpy(&v,buf+ptr,sizeof(v));
    ptr+=sizeof(v);
}
static string getstr(const char* buf,int& ptr){
    int sz;
    getint(buf,ptr,sz);
    ptr+=sz;
    return string(buf+ptr-sz,sz);
}

template<class MP,typename T,typename TT>
static int maptomem(MP& mp,char** mem,string(*key)(const T&),string(*val)(const TT&)){
    char* buf=(char*)malloc(64*1024*1024);
    int ptr=0;
    putint(buf,ptr,mp.size());
    for(const auto i:mp){
        putstr(buf,ptr,key(i.first));
        putstr(buf,ptr,val(i.second));
    }
    *mem=(char*)realloc(buf,ptr);
    return ptr;
} 
template<class MP,typename T>
static int settomem(MP& mp,char** mem,string(*val)(const T&)){
    char* buf=(char*)malloc(64*1024*1024);
    int ptr=0;
    putint(buf,ptr,autosize(mp));
    for(const auto i:mp){
        putstr(buf,ptr,val(i));
    }
    *mem=(char*)realloc(buf,ptr);
    return ptr;
} 
template<class MP,typename T,typename TT>
static int memtomap(MP& mp,char* buf,void(*key)(const string&,T&),void(*val)(const string&,TT&)){
    int ptr=0;
    int sz;
    getint(buf,ptr,sz);
    T k;TT v;
    for(int i=0;i<sz;++i){
        string kb=getstr(buf,ptr);
        string vb=getstr(buf,ptr);
        key(kb,k);
        val(vb,v);
        mp.insert({k,v});
    }
    return sz;
} 
template<class MP,typename TT>
static int memtoset(MP& mp,char* buf,void(*val)(const string&,TT&)){
    int ptr=0;
    int sz;
    getint(buf,ptr,sz);
    TT v;
    for(int i=0;i<sz;++i){
        string vb=getstr(buf,ptr);
        val(vb,v);
        mp.push_front(v);
    }
    return sz;
} 
static string h_int2str(const int& v){
    //return std::to_string(v);
    return string((char*)&v,4);
}
static void h_str2int(const string& a,int& v){
    //v=atoi(a.c_str());
      v=*((int*)a.c_str());
}
static string h_str2str(const string& v){
    return v;
}
static void h_str2str_load(const string& v,string& vv){
    vv=v;
}
static void mem2file(const char* fn,char* mem,int sz,bool fre=true){
    int fd=open(fn,O_WRONLY|O_CREAT,S_IRWXU);
    write(fd,mem,sz);
    close(fd);
    if(fre) free(mem);
}

