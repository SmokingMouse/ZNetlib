//
// Created by zhangpeng on 19-3-9.
//


#include <Loop.h>
#include <Poller.h>
#include <Channel.h>

void Loop::startLoop() {
    while(1){
    // get the event.
    // deal with the events.
        ChannelPtrList activeList;
        int time;
        poller_->Poll(&activeList,time);
        for(auto iter = activeList.begin();iter != activeList.end();++iter){
            (*iter)->handleEvent();
        }
    }
}
