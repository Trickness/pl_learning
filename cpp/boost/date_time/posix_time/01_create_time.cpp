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
}
