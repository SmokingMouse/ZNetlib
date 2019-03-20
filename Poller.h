//
// Created by zhangpeng on 19-3-8.
//

#ifndef POLLER_H
#define POLLER_H

#include <poll.h>
#include <vector>
#include <map>

class Channel;

class Poller{
public:
    using PollFdList = std::vector<struct pollfd>;
    using ChannelMap= std::map<int,Channel*>;
    using ChannelList = std::vector<Channel*>;

    Poller(){}
    ~Poller(){}

    void Poll(ChannelList* activeChannel,int time);
    void fillActiveChannels(ChannelList* activeChannel,int num);
    void updateChannel(Channel* channel);
private:
    PollFdList pollFds_;
    ChannelMap channels_;
};

#endif //MYOWNNETLIB_POLLER_H
