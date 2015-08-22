#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::posix_time;
using namespace boost::gregorian;

int main(){
    ptime p(date(2014,1,1),hours(12));
    time_period tp1(p,hours(8));
    time_period tp2(p + hours(8),hours(1));

    if(tp1.end() == tp2.begin() && tp1.is_adjacent(tp2))
        cout << "Okay" << endl;

    tp1.shift(hours(1));
    if(tp1.is_after(p))
        cout << "tp1 is after tp2 " << endl;

    // P 47
    return 0;
}
