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
        void list_insert(double_linked_list_node<T>* x);
        void list_insert(T* value);
        void list_insert(T value);
        void list_insert(double_linked_list<T> &list);
        void list_insert_left(double_linked_list_node<T>* f,double_linked_list_node<T>* x);
        void list_insert_left(double_linked_list_node<T>* f,T* value);
        void list_insert_left(double_linked_list_node<T>* f,T value);
        void list_insert_left(double_linked_list_node<T>* f,double_linked_list<T> &list);
        void list_insert_right(double_linked_list_node<T> *f,double_linked_list_node<T>* x);
        void list_insert_right(double_linked_list_node<T> *f,T* value);
        void list_insert_right(double_linked_list_node<T> *f,T value);
        void list_insert_right(double_linked_list_node<T> *f,double_linked_list<T> &list);
        double_linked_list_node<T>* list_search(T *k);
        double_linked_list_node<T>* list_search(T  k);
        double_linked_list_node<T>* list_search(double_linked_list_node<T> *k);
        double_linked_list_node<T>* list_head(void);
        bool list_delete(double_linked_list_node<T>* x);
        bool list_delete(T* value);
        bool list_delete(T  value);
        void list_clear(void);  //  It maybe cause memory leaking....
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
inline double_linked_list_node<T>* double_linked_list<T>::list_head(void){
    return this->head;
}

template<typename T>
inline void double_linked_list<T>::list_clear(void){
    this->length = 0;
    this->head = nullptr;
}

template<typename T>
void double_linked_list<T>::list_destroy(void){
    if(this->length == 0)
        return;
    double_linked_list_node<T>* curr = nullptr;
    double_linked_list_node<T>* x = this->head;
    size_t len = this->length;
    this->list_clear();
    for(int i=0;i<len;++i){
        curr = x;
        x = curr->next;
        delete curr;
    }
    x = nullptr;
    curr = nullptr;
}


template<typename T>
inline size_t double_linked_list<T>::len(void){
    return this->length;
}

template<typename T>
void double_linked_list<T>::list_insert_left(double_linked_list_node<T>* fiducial_node,
        double_linked_list_node<T>* x){
    if(this->head == nullptr){
        this->head = x;
        x->prev = x;
        x->next = x;
        this->length = 1;
        return;
    }
    if(fiducial_node == nullptr){
        auto y = this->head->left;
        x->left  = y;
        x->right = this->head;
        this->head->left = x;
        y->right = x;
    }else{
        if(!this->list_search(fiducial_node))
            return;
        auto y = fiducial_node->left;
        x->left  = y;
        x->right = fiducial_node;
        fiducial_node->left = x;
        y->right = x;
    }
    ++this->length;
    return;
}

template<typename T>
inline void double_linked_list<T>::list_insert_left(double_linked_list_node<T>* fiducial_node,
        T *value){
    auto x = new double_linked_list_node<T>(value);
    return this->list_insert_left(fiducial_node,x);
}

template<typename T>
inline void double_linked_list<T>::list_insert_left(double_linked_list_node<T>* fiducial_node,
        T value){
    auto x = new double_linked_list_node<T>(value);
    return this->list_insert_left(fiducial_node,x);
}

template<typename T>
void double_linked_list<T>::list_insert_right(double_linked_list_node<T>* fiducial_node,
        double_linked_list_node<T>* x){
    if(this->head == nullptr){
        this->head = x;
        x->prev = x;
        x->next = x;
        this->length = 1;
        return;
    }
    if(fiducial_node == nullptr){
        auto y = this->head->right;
        x->right  = y;
        x->left = this->head;
        this->head->right = x;
        y->left = x;
    }else{
        if(!this->list_search(fiducial_node))
            return;
        auto y = fiducial_node->right;
        x->right  = y;
        x->left = fiducial_node;
        fiducial_node->right = x;
        y->left = x;
    }
    ++this->length;
    return;
}

template<typename T>
inline void double_linked_list<T>::list_insert_right(double_linked_list_node<T>* fiducial_node,
        T *value){
    auto x = new double_linked_list_node<T>(value);
    return this->list_insert_right(fiducial_node,x);
}

template<typename T>
inline void double_linked_list<T>::list_insert_right(double_linked_list_node<T>* fiducial_node,
        T value){
    auto x = new double_linked_list_node<T>(value);
    return this->list_insert_right(fiducial_node,x);
}

template<typename T>
inline void double_linked_list<T>::list_insert(double_linked_list_node<T>* x){
    this->list_insert_left(nullptr,x);
}

template<typename T>
inline void double_linked_list<T>::list_insert(T* value){
    auto x = new double_linked_list_node<T>(value);
    return this->list_insert(x);
}

template<typename T>
inline void double_linked_list<T>::list_insert(T  value){
    auto x = new double_linked_list_node<T>(value);
    return this->list_insert(x);
}

template<typename T>
void double_linked_list<T>::list_insert(double_linked_list<T> &list){
    if(list.len() == 0)
        return;
    auto x = list.list_head();
    if(this->length == 0){
        this->head = x;
    }else{
        auto n = this->head->next;
        auto p = x->prev;
        this->head->next = p;
        p->prev = this->head;
        n->prev = x;
        x->next = n;
    }
    this->length += list.len();
    list.list_clear();
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
        if(*(x->key) == value)
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

