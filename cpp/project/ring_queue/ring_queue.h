#ifndef RING_QUEUE_H
#define RING_QUEUE_H

namespace{
#include "ring_queue_template.h"
#include <iostream>
#include <memory>
}

template<typename T>
std::weak_ptr<class ring_queue<T>>  make_ring_queue_reader(std::shared_ptr<T>& writer){
    return std::weak_ptr<T>(writer);
}

template<typename T>
std::shared_ptr<class ring_queue<T>>   make_ring_queue_writer(int queue_size){
    return std::make_shared<class ring_queue<T>>(queue_size);
}

#endif // RING_QUEUE_H

