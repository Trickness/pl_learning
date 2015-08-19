#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(){
    date d(2006,11,26);
    day_iterator d_iter(d);     //  默认布长为1天   == 2006-11-26

    assert(d_iter == d);
    ++d_iter;                   //  2006-11-27
    assert(d_iter == date(2006,11,27));

    year_iterator y_iter(*d_iter,8);    //  默认步长为8年
    assert(y_iter == d + days(1));
    ++y_iter;                   //  2014-11-27
    assert(y_iter->year() == 2014);

    return 0;
}
