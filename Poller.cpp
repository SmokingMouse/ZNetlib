//
// Created by zhangpeng on 19-3-9.
//

#include <Poller.h>
#include <time.h>
#include <Channel.h>

//the time waits to be packaged.
void Poller::Poll(ChannelList* activeChannel,int timeout) {
    int eventNums = poll(&*pollFds_.begin(),pollFds_.size(),timeout);

    fillActiveChannels(activeChannel,eventNums);

}

void Poller::fillActiveChannels(Poller::ChannelList *activeChannel, int num) {
    for(auto iter = pollFds_.begin();iter!=pollFds_.end()&&num>0;iter++){
        if(iter->revents > 0){
            num--;
            Channel* channel = channels_.find(iter->fd)->second;
            channel->setRevent(iter->revents);
            activeChannel->push_back(channel);
        }
    }
}

void Poller::updateChannel(Channel *channel) {
    if(channel->index() < 0){ // which means it is a new channel.
        struct pollfd new_fd;
        channel->initPollFd(&new_fd);
        pollFds_.push_back(new_fd);
        channels_[new_fd.fd] = channel;
    } else{// channel is updated, the channel's idx can't be changed.
        channel->initPollFd(&pollFds_[channel->index()]); //
    }
}
