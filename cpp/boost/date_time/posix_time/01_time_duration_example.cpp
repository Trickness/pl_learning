#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::posix_time;

int main(){
    time_duration td(1,10,30,1000); // 1 hour 10 minutes 30 second 1ms(1000 microsecond)

    hours h(1);  // 1 hour
    minutes m(10);
    seconds s(30);
    millisec ms(1);

    time_duration td2 = h + m + s + ms;

    time_duration td3 = duration_from_string("1:10:30:001");

    cout << "td [simple string] : " << to_simple_string(td) << endl;
    cout << "td [to iso string  : " << to_iso_string(td) << endl;

    cout << "td2 [simple string] : " << to_simple_string(td2) << endl;
    cout << "td2 [to iso string  : " << to_iso_string(td2) << endl;

    hours h2(-11);
    if (h2.is_negative())
        cout << "h2 is a negative" << endl;
    else
        cout << "h2 is a positive" << endl;

    time_duration td4(neg_infin);

    if (td4.is_neg_infinity())
        cout << "td4 is a negative infinitity time duartion" << endl;   
}
