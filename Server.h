//
// Created by zhangpeng on 19-3-8.
//

#ifndef SERVER_H
#define SERVER_H

// init: Address Struct.
// onConnection:
// onMessage:
#include <map>
#include <set>
#include <functional>
#include <string>
#include <sys/socket.h>
#include <InetAddr.h>
class Loop;
class Connection;

class Server{
public:
    using ConnectionPtr = Connection*;
    using ConnectionPtrSet = std::set<ConnectionPtr>;
    using CallBackFunc = std::function<void(ConnectionPtr)>;

    Server() = delete;
    Server(Loop* loop,const std::string& addr,int16_t port):loop_(loop),localAddr_(addr,port){}

    void setMessageCallBack(CallBackFunc& func){
        onMessage_ = func;
    }

    void setConnectCallBack(CallBackFunc& func){
        onConnect_ = func;
    }

    void setWriteCompleteCallBack(CallBackFunc& func){
        onConnect_ = func;
    }

private:
    Loop* loop_;
    InetAddr localAddr_;
    ConnectionPtrSet connectionPtrs_;
    CallBackFunc onMessage_;
    CallBackFunc onConnect_;
    CallBackFunc onWriteComplete_;
};

#endif //MYOWNNETLIB_SERVER_H
