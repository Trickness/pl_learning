#include <iostream>
#include <boost/smart_ptr.hpp>

using namespace std;

class test_class{
    public:
        test_class(void){
            cout << "Initlizating....." << endl;
        }
        ~test_class(){
            cout << "Deleting........." << endl;
        }
};

int main(){
    boost::scoped_ptr<test_class> p(new test_class());
    assert(p);      // false if ptr is nullptr
    // Do NOT try to delete scoped_ptr, It will crash your program
    
    return 0;
}
