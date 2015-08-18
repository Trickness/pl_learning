#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

using namespace std;
using namespace boost::gregorian;

int main(){
    date d1;                //  not_a_date_time if DATE_TIME_NO_DEFAULT not been defined
    date d2(2010,1,1);      //  使用数字构造时间
    date d3(2000,Jan,1);    //  使用英文指定月份
    date d4(d2);            //  拷贝构造

    assert(d1 == date(not_a_date_time));    //  比较一个临时对象
    assert(d2 == d4);                       //  比较
    assert(d3 < d4);                        //  支持大小比较

    cout << "d1 == " << d1 << endl;
    cout << "d2 == " << d2 << endl;
    cout << "d3 == " << d3 << endl;
    cout << "d4 == " << d4 << endl;

//    date d5 = from_string("1999-11-31");
//    date d6 = from_string("2015/1/1");
//    date d7 = from_undelimited_string("20011118");

//    cout << "d5 == " << d5 << endl;
//    cout << "d6 == " << d6 << endl;
//    cout << "d7 == " << d7 << endl;

    return 0;
}
