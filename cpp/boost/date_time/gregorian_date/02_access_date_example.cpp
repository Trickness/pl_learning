#include <iostream>
#include <assert.h>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(){
    date d(2014,4,1);
    cout << "Year  == " << d.year()  << endl;
    cout << "Month == " << d.month() << endl;
    cout << "Day   == " << d.day()   << endl;

    if(d.month() == 4)      // It can also compares with integer
        cout << "Yes the month == 4" << endl;

    date::ymd_type ymd = d.year_month_day();
    assert(ymd.year == 2014);
    assert(ymd.month== 4);
    assert(ymd.day  == 1);

    cout << date(2014,1,10).week_number()   << endl;
    cout << date(2014,1,1).week_number()    << endl;
    cout << date(2015,1,1).week_number()    << endl;

    date d2;
    if(d2.is_infinity()){
        cout << "d2 is an infinity date"    <<endl;
        if(d2.is_neg_infinity()){
            cout << "d2 is -infinity"   << endl;
        }else{
            cout << "d2 is +infinity"   << endl;
        }
    }else if(d2.is_not_a_date()){
        cout << "d2 is not a date"  << endl;
    }else if(d2.is_special()){
        cout << "d2 is a special day" << endl;
    }

    return 0;
}
