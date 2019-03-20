//
// Created by zhangpeng on 19-3-9.
//

#include <Channel.h>
#include <poll.h>

void Channel::initPollFd(struct pollfd* poll_fd) {
    poll_fd->revents = revent_;
    poll_fd->events = event_;
    poll_fd->fd = fd_;
}

void Channel::handleEvent() {
    if(revent_ & POLLNVAL){

    }
    if(revent_ & (POLLHUP | POLLERR)){}
    if(revent_ &(POLLIN | POLLRDNORM | POLLRDBAND|POLLPRI)){readFunc_();};
    if(revent_ &(POLLOUT | POLLWRBAND | POLLWRNORM)) {writeFunc_();};
}
