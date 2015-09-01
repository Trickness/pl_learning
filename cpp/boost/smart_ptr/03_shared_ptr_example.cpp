#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>
#include <string>
#include <map>

using namespace std;

void any_func(void *p){
    cout << "some operate" << endl;
}

bool bool_test(void){
    boost::shared_ptr<int> p(new int(10));
    return static_cast<bool>(p);
}

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


    typedef boost::shared_ptr<string> sp_t;
    map<sp_t, int> m;

    sp_t sp2(new string("one"));
    m[sp2] = 111;
    cout << sp << endl;     // use smart_ptr::operator<< to print pointer's value

    boost::shared_ptr<void> p3(nullptr, any_func);  // nullptr and specify deleter
    assert(bool_test());
    return 0;
}
