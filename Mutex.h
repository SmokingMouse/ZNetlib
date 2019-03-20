#ifndef MUTEX_H
#define MUTEX_H

#include<pthread.h>

class Mutex{
public:
    Mutex(){
        pthread_mutex_init(&mutex_,nullptr);
    }

    ~Mutex(){
        pthread_mutex_destroy(&mutex_);
    }

    void lock(){
        pthread_mutex_lock(&mutex_);
    }

    void unlock(){
        pthread_mutex_unlock(&mutex_);
    }

private:
    pthread_mutex_t mutex_;
};

#endif