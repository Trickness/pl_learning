#ifndef RING_QUEUE_TEMPLATE_H
#define RING_QUEUE_TEMPLATE_H

namespace{
#include <iostream>
#include <memory>       // unique_ptr (C++14)
#include <string.h>     // for memcpy
#include <stdint.h>
}

template <typename T>
class ring_queue{
public:
    explicit    ring_queue(size_t queue_size);
    ~ring_queue(void);
    std::size_t unread(void);
    bool        is_full(void);
    bool        is_empty(void);
    virtual bool                push(T value);
    virtual std::unique_ptr<T>  fetch(void);
    //virtual ring_queue<T> get(void);
    virtual void                clear(void);
    std::size_t queue_size(void);

    ring_queue(const ring_queue&) = delete;               //
    ring_queue & operator=(const ring_queue&) = delete;   //  makes this class noncopyable
    
protected:
    T*              queue;
    uint32_t        queue_front;
    uint32_t        queue_rear;
    std::size_t     queue_size_max;
};

template<typename T>
ring_queue<T>::ring_queue(size_t queue_size):
    queue_front(0),queue_rear(0),queue_size_max(queue_size+1){
    this->queue = new T[this->queue_size_max];
}

template<typename T>
ring_queue<T>::~ring_queue(){
    delete[] this->queue;
}

template<typename T>
inline std::size_t ring_queue<T>::unread(){
    return (this->queue_front+this->queue_size_max-this->queue_rear)%this->queue_size_max;
}

template<typename T>
inline bool ring_queue<T>::is_full(){
    return (this->unread()+1 == this->queue_size_max);
}

template<typename T>
inline bool ring_queue<T>::is_empty(){
    return (this->unread() == 0);
}

template<typename T>
inline bool ring_queue<T>::push(T value){
    if(this->is_full()){
        std::cout << "Queue overflowing" << std::endl;
        return false;
    }
    memcpy((void*)&(this->queue[this->queue_front]),(void*)&value,sizeof(value));      // use sizeof(value) instead of sizeof(T)
    this->queue_front = (this->queue_front + 1)%this->queue_size_max;
    return true;
}

template<typename T>
inline std::unique_ptr<T> ring_queue<T>::fetch(){
    if(this->is_empty()){
        return nullptr;
    }else{
        this->queue_rear = (this->queue_rear + 1)%this->queue_size_max;
        return std::make_unique<T>(this->queue[(this->queue_rear-1+this->queue_size_max)%this->queue_size_max]);
    }
}

template<typename T>
inline std::size_t ring_queue<T>::queue_size(){
    return this->queue_size_max-1;
}

template<typename T>
inline void ring_queue<T>::clear(){
    memset(this->queue,0,sizeof(T)*this->queue_size_max);
    this->queue_front = 0;
    this->queue_rear = 0;
}

#endif // RING_QUEUE_H

