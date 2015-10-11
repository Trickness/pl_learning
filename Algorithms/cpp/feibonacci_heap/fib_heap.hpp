#ifndef SWZ_FIB_HEAP_HPP
#define SWZ_FIB_HEAP_HPP

namespace{
#include <iostream>
#include "../linked_list/double_linked_list.hpp"
}

template<typename T>
class fib_node{
    public:
        fib_node(T value):key(value),p(nullptr),mark(false){}
        fib_node(T* value):key(*value),p(nullptr),mark(false){}
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
        bool mark;

};

template<typename T>
class fib_heap{
    public:
        fib_heap():min(nullptr),n(0){}
        double_linked_list<fib_node<T> > root_list;
        void fib_heap_insert(fib_node<T> x);
        fib_node<T> *get_min(void);

    public:
        doouble_linked_list<fib_node<T> >  root_list;
        fib_node<T> *min;
        size_t  n;  // number of nodes
};


template<typename T>
fib_node<T>* fib_heap<T>::get_min(void){
}

template<typename T>
void fib_heap<T>::fib_heap_insert(fib_node<T> _n){
    fib_node<T> *x = new fib_node<T>;
    x->fib_node(_n);
    x->child_list.list_destroy();
    //  It will led to....
    //      x.child = nullptr;
    //      x.degree= nullptr;
    x->p    = nullptr;      // root list items
    x->mark = false;

    this->root_list.list_insert()

    if(this->min == nullptr){
        this->min = x;
    }else{
        if(x->key < this->min->key){
        }
    }
}

#endif
