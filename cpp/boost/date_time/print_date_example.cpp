#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(){
    // There's three ways to print date:
    //      1. to_simple_string(date);          YYYY-mm-DD
    //      2. to_iso_string(date);             YYYYMMDD
    //      3. to_iso_extended_string(date);    YYYY-MM-DD
    date d(2008,11,20);
    cout << " Standard output format : " << d << endl;
    cout << "to_simple_string format : " << to_simple_string(d) << endl;
    cout << "   to_iso_string format : " << to_iso_string(d) << endl;
    cout << "to_iso_extended_string  : " << to_iso_extended_string(d) << endl;
    return 0;
}
