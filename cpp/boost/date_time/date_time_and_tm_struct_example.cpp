#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(){
    //  You can use to_tm(date) to get tm struct from a date_time object
    //  You can also use from_tm(tm) to turn a tm struct into date_time object
    date d(2014,2,1);
    tm t = to_tm(d);
    date d2 = date_from_tm(t);
    if (d == d2){
        cout << "They are the same!" << endl;
    }else{
        cout << "Impossible!" << endl;
    }
    return 0;
}
