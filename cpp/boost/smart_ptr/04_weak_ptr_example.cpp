#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/weak_ptr.hpp>

using namespace std;

int main(){
    auto sp = boost::make_shared<int>(20);
    cout << "sp's count = " << sp.use_count() << endl;
    boost::weak_ptr<int> wp(sp);
    cout << "sp's count = " << sp.use_count() << endl;
    cout << "sp's value = " << *wp.lock() << endl;
    cout << "sp's count = " << sp.use_count() << endl;
    sp.reset();
    assert(wp.expired());
    assert(!wp.lock());
    return 0;
}
