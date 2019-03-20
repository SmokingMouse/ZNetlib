//
// Created by zhangpeng on 19-3-9.
//

#ifndef INETADDR_H
#define INETADDR_H

#include <netinet/in.h> // the ip struct. and transfer port host schema to net schema.
#include <arpa/inet.h> // transfer ip dot schema to binary schema.
#include <string>

class InetAddr{
public:
    InetAddr() = delete;
    InetAddr(const std::string& ip,uint16_t port){
        inet_aton(ip.c_str(),&addr.sin_addr);
        htons(port);
        addr.sin_family = AF_INET;
    }
private:
    struct sockaddr_in addr;
};

#endif //MYOWNNETLIB_INETADDR_H
