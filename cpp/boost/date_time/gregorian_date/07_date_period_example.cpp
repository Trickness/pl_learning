#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(){
    //  1. date_preiod(date from,date to)
    //      'from' should larger than 'to'
    //  2. date_preiod(date base,days d)
    date_period dp1(date(2014,1,1),days(20));
    date_period dp2(date(2014,1,1),date(2014,5,1));

    cout << "dp1 begin from " << dp1.begin() << "  end to " << dp1.end();
    cout << "  last " << dp1.last().day() << " days" << endl;

    cout << "dp2 begin from " << dp2.begin() << "  end to " << dp2.end();
    cout << "  last " << dp2.last().day() << " days" << endl;

    if (dp1 > dp2)
        cout << "dp1 is longer than dp2" << endl;
    else
        cout << "dp2 is longer than dp1" << endl;
    return 0;
}
