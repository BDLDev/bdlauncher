#pragma once
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include<functional>
#include<vector>
using std::vector;
using std::string;
using namespace rapidjson;
struct BaseForm{
    virtual void setID(int i)=0;
    virtual string getstr()=0;
    virtual int getid()=0;
    virtual void process(const string&)=0;
};

struct Form:BaseForm{
    int fid;
    Document dc;
    vector<string> labels;
    std::function< void(const string&)> cb;
    Form(std::function< void(const string&)> cbx){
        cb=cbx;
        dc.SetObject();
        dc.AddMember("type","form",dc.GetAllocator());
        dc.AddMember("title","",dc.GetAllocator());
        dc.AddMember("content","",dc.GetAllocator());
        Value x(kArrayType);
        dc.AddMember("buttons",x,dc.GetAllocator());
    }
    void process(const string& d){
        //printf("gui get %s\n",d.c_str());
        if(d[0]=='n') return;
        int idx=atoi(d.c_str());
        cb(labels[idx]);
    }
    void setID(int i){
        fid=i;
    }
    int getid(){
        return fid;
    }
    string getstr(){
        StringBuffer buf;
        Writer<StringBuffer> writer(buf);
        dc.Accept(writer);
        return string(buf.GetString());
    }
    Form* addButton(const string& text,const string& label){
        Value bt(kObjectType);
        Value ss;
        ss.SetString(text.data(),text.size(),dc.GetAllocator());
        bt.AddMember("text",ss,dc.GetAllocator());
        dc["buttons"].PushBack(bt,dc.GetAllocator());
        labels.emplace_back(label);
        return this;
    }
    Form* setContent(const string& text){
        dc["content"].SetString(text.c_str(),dc.GetAllocator());
        return this;
    }
    Form* setTitle(const string& text){
        dc["title"].SetString(text.c_str(),dc.GetAllocator());
        return this;
    }
};
struct SimpleInput:BaseForm{
    int fid;
    Document dc;
    std::function< void(const string&)> cb;
    SimpleInput(const string& ti,std::function< void(const string&)> cbx){
        cb=cbx;
        Value ss;
        dc.SetObject();
        ss.SetString(ti.data(),ti.size(),dc.GetAllocator());
        dc.AddMember("type","custom_form",dc.GetAllocator());
        dc.AddMember("title",ss,dc.GetAllocator());
        Value x(kArrayType);
        dc.AddMember("content",x,dc.GetAllocator());
    }
    void process(const string& d){
        /*dc.Parse(d.c_str());
        if(!dc.IsArray()) return;
        cb(string(dc.GetArray().Begin()->GetString()));*/
        if(d[0]=='n') return;
        cb(string(d.substr(2,d.size()-5)));
    }
    int getid(){
        return fid;
    }
    void setID(int i){
        fid=i;
    }
    string getstr(){
        StringBuffer buf;
        Writer<StringBuffer> writer(buf);
        dc.Accept(writer);
        return string(buf.GetString());
    }
    SimpleInput* addInput(const string& text){
        Value tmp(kObjectType);
        Value ss;
        ss.SetString(text.data(),text.size(),dc.GetAllocator());
        tmp.AddMember("type","input",dc.GetAllocator())
        .AddMember("text",ss,dc.GetAllocator())
        .AddMember("placeholder",Value(kNullType),dc.GetAllocator())
        .AddMember("default",Value(kNullType),dc.GetAllocator());
        dc["content"].GetArray().PushBack(tmp,dc.GetAllocator());
        return this;
    }
};
BDL_EXPORT void sendForm(ServerPlayer& sp,BaseForm* fm);
BDL_EXPORT void sendForm(const string& sp,BaseForm* fm);

BDL_EXPORT void gui_ChoosePlayer(ServerPlayer* sp,const string& text,const string& title,std::function<void(const string&)> cb);
BDL_EXPORT void gui_GetInput(ServerPlayer* sp,const string& text,const string& title,std::function<void(const string&)> cb);
using std::pair;
BDL_EXPORT void gui_Buttons(ServerPlayer* sp,const string& text,const string& title,const list<pair<string,std::function<void()> > >* li);
