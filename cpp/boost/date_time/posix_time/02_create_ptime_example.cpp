#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

int main(){
    ptime p1 = time_from_string("2014-6-8 01:00:00");
    ptime p2 = from_iso_string("20140608T010000");
    ptime p(date(2014,6,8),hours(1));

    ptime p3 = second_clock::local_time();
    ptime p4 = microsec_clock::universal_time();

    cout << "p  = " << p  << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "p4 = " << p4 << endl; 

    ptime p5(pos_infin);
    if (p5.is_pos_infinity())
        cout << "p5 is a post infinity time" << endl;
    else
        cout << "p5 is not a post infinity time" << endl;
    ptime p6(not_a_date_time);
    if(p6.is_not_a_date_time())
        cout << "p6 is not a date time" << endl;
    else
        cout << "p6 is a daet time : " << p6 << endl;
    return 0;
}
