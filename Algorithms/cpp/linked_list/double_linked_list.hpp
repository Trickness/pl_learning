#ifndef SWZ_LINKED_LIST
#define SWZ_LINKED_LIST

namespace{
#include <iostream>
}

template<typename T>
class double_linked_list_node{
    public:
        explicit double_linked_list_node(T* value);
        explicit double_linked_list_node(T  value);
        ~double_linked_list_node() = default;
        T* key;
        double_linked_list_node *prev;
        double_linked_list_node *next;
        double_linked_list_node *&right =   next;
        double_linked_list_node *&left =    prev;
};

template<typename T>
class double_linked_list{
    public:
        double_linked_list(void);
        ~double_linked_list(void);
        size_t len(void);
        bool list_insert(double_linked_list_node<T>* x);
        bool list_insert(T* value);
        bool list_insert(T value);
        double_linked_list_node<T>* list_search(T *k);
        double_linked_list_node<T>* list_search(T  k);
        double_linked_list_node<T>* list_search(double_linked_list_node<T> *k);
        bool list_delete(double_linked_list_node<T>* x);
        bool list_delete(T* value);
        bool list_delete(T  value);
        void list_destroy(void);
    protected:
        size_t length;
        double_linked_list_node<T> *head;
};

template<typename T>
double_linked_list_node<T>::double_linked_list_node(T *value)
    :key(value),prev(nullptr),next(nullptr){
}

template<typename T>
double_linked_list_node<T>::double_linked_list_node(T value)
    :prev(nullptr),next(nullptr){
    this->key = new T(value);
}

template<typename T>
double_linked_list<T>::double_linked_list(void){
    this->head = nullptr;
    this->length = 0;
}

template<typename T>
double_linked_list<T>::~double_linked_list(void){
    this->list_destroy();
}

template<typename T>
void double_linked_list<T>::list_destroy(void){
    if(this->length == 0)
        return;
    double_linked_list_node<T>* curr = nullptr;
    double_linked_list_node<T>* x = this->head;
    this->length = 0;
    this->head = nullptr;
    for(int i=0;i<this->length;i++){
        curr = x;
        x = curr->next;
        delete curr;
    }
}


template<typename T>
inline size_t double_linked_list<T>::len(void){
    return this->length;
}

template<typename T>
bool double_linked_list<T>::list_insert(double_linked_list_node<T>* x){
    if(this->length == 0){
        this->head = x;
        x->next = x;
        x->prev = x;
        this->length = 1;
        return 0;
    }
    x->prev = this->head;
    x->next = this->head->next;
    x->next->prev = x;
    x->prev->next = x;
    ++this->length;
}

template<typename T>
bool double_linked_list<T>::list_insert(T* value){
    auto* x = new double_linked_list_node<T>(value);
    return this->list_insert(x);
}

template<typename T>
bool double_linked_list<T>::list_insert(T  value){
    auto* x = new double_linked_list_node<T>(value);
    return this->list_insert(x);
}

template<typename T>
double_linked_list_node<T>* double_linked_list<T>::list_search(T* value){
    if(this->head->key == value)
        return this->head;
    for(auto x=this->head->next;x!=this->head;x=x->next)
        if(x->key == value)
            return x;
    return nullptr;
}

template<typename T>
double_linked_list_node<T>* double_linked_list<T>::list_search(T  value){
    if(*(this->head->key) == value)
        return this->head;
    for(auto x=this->head->next;x!=this->head;x=x->next)
        if(*x->key == value)
            return x;
    return nullptr;
}

template<typename T>
double_linked_list_node<T>* double_linked_list<T>::list_search(double_linked_list_node<T>*value){
    if(this->head == value)
        return this->head;
    for(auto x=this->head->next;x!=this->head;x=x->next)
        if(x == value)
            return x;
    return nullptr;
}

template<typename T>
bool double_linked_list<T>::list_delete(double_linked_list_node<T> *x){
    if(this->length == 0)
        return false;
    if(this->list_search(x)){
        if(x == this->head)
            this->head = x->next;
        if(this->length == 1)
            this->head = nullptr;
        x->next->prev = x->prev;
        x->prev->next = x->next;
        delete x;
        --this->length;
        return true;
    }
    return false;
}

template<typename T>
inline bool double_linked_list<T>::list_delete(T *value){
    return this->list_delete(this->list_search(value));
}

template<typename T>
inline bool double_linked_list<T>::list_delete(T  value){
    return this->list_delete(this->list_search(value));
}

#endif

