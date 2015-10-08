#ifndef SWZ_FIB_HEAP_HPP
#define SWZ_FIB_HEAP_HPP

namespace{
#include <iostream>
#include "../double_linked_list.hpp"
}

template<typename T>
class fib_heap{
    public:
        fib_heap(void);
        ~fib_heap(void);
        void destroy(void);

        fib_heap<T>* p;
        fib_heap<T>* ;
};
