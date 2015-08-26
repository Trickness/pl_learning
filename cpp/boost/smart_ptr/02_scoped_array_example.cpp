#include <iostream>
#include <boost/smart_ptr.hpp>

using namespace std;

int main(){
    int *arr = new int[100];
    boost::scoped_array<int> sa(arr);

    fill_n(&sa[0],100,5);
    for(int i=0;i<100;++i)
        cout << sa[i] << " " << endl;
    return 0;
}
