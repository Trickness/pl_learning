#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;

class node{
    public:
        ~node(){
            cout << "Delete" << endl;
        }
        typedef boost::shared_ptr<node> ptr_type;
        ptr_type next;
};

int main(){
    auto p1 = boost::make_shared<node>();
    auto p2 = boost::make_shared<node>();

    p1->next = p2;
    p2->next = p1;
    
    cout << "p1's use_count = " << p1.use_count() << endl;
    cout << "p2's use_count = " << p2.use_count() << endl;

    return 0;
}   // cannot be deleted
