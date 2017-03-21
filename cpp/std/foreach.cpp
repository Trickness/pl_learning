#include <iostream>
#include <algorithm>
#include "class_a.hpp"

int main(){
    A arr[] = {A('A'),A('B'),A('C')};
    /*A brr[3];
    brr[0] = A('a');
    brr[1] = A('b');
    brr[2] = A('c');*/
    std::for_each(&arr[0],&arr[0]+sizeof(arr)/sizeof(arr[0]),[](A& a){a.print();});
    return 0;
}
