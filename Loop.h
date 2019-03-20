//
// Created by zhangpeng on 19-3-8.
//
#ifndef LOOP_H
#define LOOP_H

#include <vector>

class Poller;
class Channel;

class Loop{
public:
    using ChannelPtrList = std::vector<Channel*>;
    Loop(){}

    void startLoop();



private:
    Poller* poller_;

};

#endif //MYOWNNETLIB_LOOP_H
