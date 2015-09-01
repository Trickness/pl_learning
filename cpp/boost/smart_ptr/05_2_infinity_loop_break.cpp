#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/weak_ptr.hpp>

using namespace std;

class node{
    public:
        ~node(){
            cout << "Delete" << endl;
        }
        typedef boost::weak_ptr<node> ptr_type;
        ptr_type next;
};

int main(){
    auto p1 = boost::make_shared<node>();
    auto p2 = boost::make_shared<node>();

    p1->next = p2;
    p2->next = p1;
    
    cout << "p1's use_count = " << p1.use_count() << endl;
    cout << "p2's use_count = " << p2.use_count() << endl;

    assert(!p1->next.expired());

    return 0;
}   // p1&p2 will be deleted
