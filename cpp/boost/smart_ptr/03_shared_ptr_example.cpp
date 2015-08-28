#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>

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

    auto sp = boost::make_shared<string>("make_shared");
    auto spv= boost::make_shared<vector<int> >(10,2);
    for(auto i = spv->begin(); i != spv->end(); ++i)
        cout << *i << endl;
    return 0;
}
