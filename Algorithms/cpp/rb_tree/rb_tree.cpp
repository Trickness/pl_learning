#include <iostream>

enum rb_tree_node_color{
    COLOR_RED,
    COLOR_BLACK
};

struct rb_tree_node{
    rb_tree_node(rb_tree_node* parent,int k)
        :p(parent),key(k){
        this->left  = nullptr;
        this->right = nullptr;
        this->key   = 0;
        this->color = rb_tree_node_color::COLOR_RED;
    }
    enum rb_tree_node_color color;
    int key;
    rb_tree_node* left;
    rb_tree_node* right;
    rb_tree_node* p;        // parent
};

class rb_tree{
    public:
        rb_tree(){
            this->root = nullptr;
        }
        ~rb_tree(){
        }

    public:
        rb_tree_node    *root;
        size_t          size;
};

bool left_rotate(rb_tree &T,rb_tree_node* x){
    // the tree should be locked when rotating
    if (x == nullptr)
        return false;
    if (x->right == nullptr)
        return false;
    rb_tree_node *y = x->right;  // set y;
    x->right = y->left;           // --|
    if(y->left != nullptr)       // - turn y's left subtree into x's right subtree
        y->left->p = x;           // --|
    y->p = x->p;                  // link x's parent to y
    if(x->p = nullptr){
        T.root = y;
        y->p = nullptr;
    }else if (x == x->p->left){
        x->p->left = y;
    }else{
        x->p->right = y;
    }
    x->p = y;
    return true;
}

bool right_rotate(rb_tree &T,rb_tree_node* y){
    if(y == nullptr)
        return false;
    if(y->left == nullptr)
        return false;
    rb_tree_node *x = y->left;
    if(x->right != nullptr)
        x->right->p = y;
    y->left = x->right;
    if (y->p == nullptr){
        T.root = x;
        x->p = nullptr;
    }else if(y == y->p->left){
        y->p->left = x;
    }else{
        y->p->right = x;
    }
    y->p = x;
    x->right = y;
    return true;
}

 int delete_rb_tree(rb_tree &T,rb_tree_node* x = nullptr){
    if(T.size == 0)
        return 0;
    if(x != nullptr){
        if(x->left != nullptr)
            delete_rb_tree(T,x->left);
        if(x->right != nullptr)
            delete_rb_tree(T,x->right);
        delete x;
        x = nullptr;
        --T.size;
    }else{
        delete_rb_tree(T,T.root);
    }
    // if rb_tree not been fully deleted
    //  We may call rb_tree_fixup
    //  buf HOW-TO??
     return 0;
 }

bool rb_tree_inser(rb_tree &T, rb_tree_node *x = nullptr){
    if(x == nullptr)
        return false;
    if(T.size == 0){
        T.root = x;
        x->left = nullptr;
        x->right= nullptr;
        x->p    = nullptr;
        x->color = rb_tree_node_color::COLOR_BLACK;
    }
        
}

int main(){
    return 0;
}
