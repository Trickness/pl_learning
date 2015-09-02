#include <iostream>
#include <boost/noncopyable.hpp>

class do_not_copy: boost::noncopyable{
    public:
        do_not_copy(){}
};

int main(){
    do_not_copy d1;
    do_not_copy d2(d1);     //  error!
    do_not_copy d3;
    d3 = d1;                //  noncopyable!
    return 0;
}
