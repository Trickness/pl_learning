#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(){
    weeks w(3);     // 3 weeks
    cout << "Days of 3 weeks = " << w.days() << endl;

    months m(5);
    years  y(2);

    months m2 = y + m;      //  2 Years and 5 months
    cout << "Months of 2 years and 5 months is " << m2.number_of_months() << endl;
    cout << "Years of 2 years x 2 is " << (y * 2).number_of_years() << endl;
    return 0;
}
