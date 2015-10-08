#include <iostream>
#include "double_linked_list.hpp"

using namespace std;


int main(){
    double_linked_list<int> L;
    L.list_insert(new int(3));
    L.list_insert(new int(4));
    L.list_insert(new int(5));
    L.list_insert(new int(6));
    L.list_insert(new int(7));
    cout << L.list_delete(L.list_search(3)) << endl;
    cout << *(L.list_search(4)->key) << endl;
    cout << L.len() << endl;
}
