#ifndef SWZ_FIB_HEAP_HPP
#define SWZ_FIB_HEAP_HPP

namespace{
#include <iostream>
#include "../linked_list/double_linked_list.hpp"
}

template<typename T>
class fib_node{
    public:
        fib_node(T value):key(value){}
        fib_node(T* value):key(*value){}
        fib_node & operator=(const fib_node<T>& n){
            this->key   = n.key;
            this->p     = n.p;
            this->child_list->clear();
            this->child_list.list_destroy();
            this->child_list.list_insert(n.child_list);
        }
        fib_node & operator=(const fib_node<T>* n){
            this->key   = n->key;
            this->p     = n->p;
            this->child_list->clear();
            this->child_list.list_destroy();
            this->child_list.list_insert(n->child_list);
        }

    public:
        double_linked_list<T> child_list;
        const size_t &dgree = child_list.len();               // unmodifiable
        const fib_node<T>* &child = child_list.list_head();   // unmodifiable
        T key;
        fib_node<T>* p;

};

template<typename T>
class fib_heap{
    public:
        fib_heap(){}
        fib_node<T>* min(void);
        double_linked_list<fib_node<T> > root_list;
        void fib_heap_insert(fib_node<T> x);
};


template<typename T>
fib_node<T>* fib_heap<T>::min(void){
}

template<typename T>
void fib_heap<T>::fib_heap_insert(fib_node<T> _n){
    fib_node<T> x = _n;
    x.child_list.list_destroy();
    x.p = nullptr;      // root list items
}

#endif
