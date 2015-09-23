#ifndef RING_QUEUE_H
#define RING_QUEUE_H

namespace{
#include "ring_queue_template.h"
#include <iostream>
#include <memory>
}

template<typename T>
std::weak_ptr<T>    make_ring_queue_reader(std::shared_ptr& writer){
}

template<typename T>
std::smart_ptr<T>   make_ring_queue_writer(int queue_size){
}

#endif // RING_QUEUE_H

