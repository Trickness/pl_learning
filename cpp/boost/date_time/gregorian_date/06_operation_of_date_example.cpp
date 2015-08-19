#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(){
    date d1(2000,1,1);
    date d2(2014,11,18);
    cout << "From 2000-1-1 to 2014-11-18 there's " << d2-d1 << " days" << endl;

    d1 += days(10);         // 2000-1-11
    d1 += months(2);        // 2000-3-11
    d1 -= weeks(1);         // 2000-3-4
    cout << "Then d1 is " << d1 << endl;

    d2 -= years(10);        // 2004-11-18
    cout << "Then d2 is " << d2 << endl;
    return 0;
}
