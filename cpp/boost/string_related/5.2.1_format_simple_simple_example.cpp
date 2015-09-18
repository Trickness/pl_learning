#include <iostream>
#include <boost/format.hpp>

using namespace std;

int main(){
    cout << boost::format("%s:%d+%d=%d") %"sum" % 1 % 2 % (1+2) << endl;
    boost::format fmt("(%1% + %2%) * %2% = %3%\n");
    fmt % 2 % 5 ;
    fmt % ((2+5)*5);
    cout << fmt.str() ;
}
