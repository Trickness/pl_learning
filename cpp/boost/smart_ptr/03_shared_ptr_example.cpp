#include <iostream>
#include <boost/smart_ptr.hpp>

using namespace std;

int main(){
    boost::shared_ptr<int> p(new int);
    *p = 10;
    cout << *p << endl;
    cout << "Count of p is " << p.use_count() << endl;
    int* int_ptr = new int;
    boost::shared_ptr<int> p2(p);
    *int_ptr = 20;
    cout << *p2 << endl;
    cout << "Count of p is " << p2.use_count() << endl;
    return 0;
}
