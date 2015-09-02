#define BOOST_SYSTEM_NO_DEPRECATED
#include <iostream>
#include <boost/pool/object_pool.hpp>
#include <string>

using namespace std;

struct demo_class{
    public:
        int a,b,c;
        demo_class(int x = 1, int y = 2, int z = 3):
            a(x),b(y),c(z){}
};

int main(){
    boost::object_pool<demo_class> p1;

    auto p = p1.malloc();
    assert(p1.is_from(p));

    cout << "p1 is not been initialized so value is " << p->a << endl;

    p = p1.construct(7,8,9);

    cout << "after been initialized p's value is " << p->a << endl;

    boost::object_pool<string> pls;
    for (int i = 0; i < 10 ; ++i){
        string *ps = pls.construct("Hello object_pool");
        cout << *ps << endl;
    }

    return 0;
}
