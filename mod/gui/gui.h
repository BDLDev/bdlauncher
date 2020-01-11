#pragma once
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include<functional>
#include<vector>
using std::vector;
using std::string;
using namespace rapidjson;
constexpr string_view button_json="{\"type\":\"form\",\"title\":\"";
constexpr string_view input_json="{\"type\":\"custom_form\",\"title\":\""; //content
struct SharedForm{
    bool needfree;
    bool isInput;
    bool hasSerialed;
    unsigned char labcnt;
    int fid;
    SPBuf<2048> buf;
    string_view labels[128];
    function<void(ServerPlayer*,string_view,int)> cb;
    SharedForm(string_view title,string_view cont,bool nedfree=true,bool isInp=false){
        needfree=nedfree;isInput=isInp;hasSerialed=false;labcnt=0;
        if(isInput){
            buf.write(input_json);
            buf.write(title);
            buf.write("\",\"content\":[");
        }else{
            buf.write(button_json);
            buf.write(title);
            buf.write("\",\"content\":\""sv);
            buf.write(cont);
            buf.write("\",\"buttons\":[");
        }
    }
    void process(ServerPlayer* sp,string_view d){
        if(d.size()==0) return;
        if(d[0]=='n') return;
        if(isInput)
            cb(sp,d.substr(2,d.size()-5),0);
        else{
            auto idx=atoi(d);
            if(idx>=0 && idx<labcnt)
                cb(sp,labels[idx],idx);
        }
    }
    void addInput(string_view text){
        assert(isInput);
        buf.write("{\"type\":\"input\",\"placeholder\":null,\"default\":null,\"text\":\"");
        buf.write(text);
        buf.write("\"}]}"); //end everything
    }
    void addButton(string_view text){
        assert(!isInput);
        if(buf.buf[buf.ptr-1]=='}'){
            buf.write(","sv);
        }
        buf.write("{\"text\":\"");
        assert(labcnt<128);
        labels[labcnt++]={buf.buf+buf.ptr,text.size()};
        buf.write(text);
        buf.write("\"}");
    }
    string_view serial(){
        if(hasSerialed || isInput) return buf.get();
        buf.write("]}"); //end button json
        hasSerialed=true;
        return buf.get();
    }
};

BDL_EXPORT void sendForm(ServerPlayer& sp,SharedForm* fm);
BDL_EXPORT SharedForm* getForm(string_view title,string_view cont,bool isInp=false);
BDL_EXPORT void gui_ChoosePlayer(ServerPlayer* sp,string_view text,string_view title,std::function<void(ServerPlayer*,string_view)> const& cb);
