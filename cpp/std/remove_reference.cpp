#include <iostream>
#include <type_traits>

using namespace std;

template<class T1, class T2>
void print_is_same(){
    cout << is_same<T1,T2>() << '\n';
}

int main(){
    cout << boolalpha;

    print_is_same<int, int>();
    print_is_same<int, int &>();
    print_is_same<int, int &&>();

    print_is_same<int, std::remove_reference<int>::type>();
    print_is_same<int, std::remove_reference<int &>::type>();
    print_is_same<int, std::remove_reference<int &&>::type>();
}