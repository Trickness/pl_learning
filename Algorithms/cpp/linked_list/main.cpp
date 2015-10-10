#include <iostream>
#include "double_linked_list.hpp"

using namespace std;


int main(){
    double_linked_list<int> L;
    L.list_insert(3);
    L.list_insert(4);
    L.list_insert(5);
    double_linked_list<int> L2;
    L2.list_insert(6);
    L2.list_insert(7);
    L2.list_insert(8);
    L.list_insert_left(L.list_search(4),L2);
    L.list_print();
}
