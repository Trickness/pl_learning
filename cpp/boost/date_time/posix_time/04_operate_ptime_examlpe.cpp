#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

int main(){
    ptime p(date(2010,3,20),hours(12) + minutes(30));   // 2010-3-20-12:30
    date d = p.date();
    time_duration td = p.time_of_day();
    cout << to_simple_string(d);
    cout << " " << to_simple_string(td) << endl;
    return 0;
}
