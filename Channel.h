//
// Created by zhangpeng on 19-3-8.
//

#ifndef CHANNEL_H
#define CHANNEL_H

#include <functional>

class Channel{
public:
    using CallBackFunc = std::function<void()>;

    void setRevent(short revent){
        revent_ = revent;
    }

    int index(){return idx_;}

    void initPollFd(struct pollfd*);

    void handleEvent();
private:
    int idx_;
    int fd_;
    short event_;
    short revent_;
    CallBackFunc readFunc_;
    CallBackFunc writeFunc_;
    CallBackFunc errorFunc_;
};

#endif //MYOWNNETLIB_CHANNEL_H
