#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(){
    //  There's shitf() and expand() in date_period
    //      date_period.shift()     将区间平移n天而长度不变
    //      date_period.expand()    将区间向两边延伸n天
    date_period dp(date(2014,1,1),days(20));    //  从2014-1-1开始的20天
    dp.shift(days(3));              //  From 2014-1-4 to 2014-1-24
    cout << "dp's begin() = " << dp.begin() << "  end() = " << dp.end();
    cout << "It lasts " << dp.length().days() << " days" << endl;

    dp.expand(days(3));
    cout << "After date_preiod.expand(days(3)) ------" << endl;
    cout << "dp's begin() = " << dp.begin() << "  end() = " << dp.end();
    cout << "  It lasts " << dp.length().days() << " days" << endl;

    return 0;
}
