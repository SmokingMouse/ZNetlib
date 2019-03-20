#ifndef MUTEX_GUARD_H
#define MUTEX_GUARD_H
#include<Mutex.h>

class MutexGuard{
public:
    MutexGuard() = delete;
    MutexGuard(Mutex& mutex):mutex_(mutex){
        mutex_.lock();
    }
    ~MutexGuard(){
        mutex_.unlock();
    }
    
private:
    Mutex& mutex_;
};

#endif