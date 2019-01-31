#pragma once
#include<bits/stdc++.h>
template<class T>
static void maptofile(T& a,std::ostream& b){
  for(auto c:a){
    std::string tmpline=std::to_string(c.first)+":"+std::to_string(c.second);
    b<<tmpline<<"\n";
  }
}
template<class T,class T1,class T2>
static void filetomap(T& mp,std::istream& a,T1(*cb1)(std::string&),T2(*cb2)(std::string&)){
  std::string tmp;
  while(!a.eof()){
    getline(a,tmp,':');
    if(tmp.length()==0) continue;
    T1 iT1=cb1(tmp);
    getline(a,tmp,'\n');
    T2 iT2=cb2(tmp);
    mp[iT1]=iT2;
  }
}
template<class T>
static void listtofile(T& a,std::ostream& b){
  for(auto c:a){
    std::string tmpline=std::to_string(c);
    b<<tmpline<<"\n";
  }
}
template<class T,class T1>
static void listtofile(T& a,std::ostream& b,std::string(*cb)(T1&)){
  for(auto c:a){
    std::string tmpline=cb(c);
    b<<tmpline<<"\n";
  }
}
template<class T,class T1>
static void filetolist(T& mp,std::istream& a,T1(*cb1)(std::string&)){
  std::string tmp;
  while(!a.eof()){
    getline(a,tmp);
    if(tmp.length()<=1) continue;
    T1 iT1=cb1(tmp);
    mp.push_front(iT1);
  }
}

