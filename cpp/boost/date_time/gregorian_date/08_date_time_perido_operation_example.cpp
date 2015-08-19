#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(){
    //  There's shitf() and expand() in date_period
    //      date_period.shift()     将区间平移n天而长度不变
    //      date_period.expand()    将区间向两边延伸n天
    date_period dp(date(2014,1,2),days(20));    //  从2014-1-1开始的20天
    dp.shift(days(3));              //  From 2014-1-4 to 2014-1-24
    cout << "dp's begin() = " << dp.begin() << "  end() = " << dp.end();
    cout << "It lasts " << dp.length().days() << " days" << endl;

    dp.expand(days(3));
    cout << "After date_preiod.expand(days(3)) ------" << endl;
    cout << "dp's begin() = " << dp.begin() << "  end() = " << dp.end();
    cout << "  It lasts " << dp.length().days() << " days" << endl;

    // date_period.is_before(date)/is_after(date)
    // date_period.contains(date)
    // date_period.intersects(date)             //  是否存在交集
    // date_period.is_adjacent(date_period)     //  是否相邻

    date_period dp2(date(2014,2,1),days(30));
    if (dp.is_before(date(2014,1,1)))
        cout << "dp is before 2014-1-1" << endl;
    else if(dp.is_after(date(2014,1,1)))
        cout << "dp is after 2014-1-1" << endl;
    else if(dp.contains(date(2014,1,1)))
        cout << "dp contains 2014-1-1" << endl;
    else
        cout << "What's up?" << endl;


    // date_period.merge(date_period)   // 返回两个date_period的并集
    //                                      如果两个date_period无交集且不相邻
    //                                      返回无效区间
    // date_period.span(date_period)    // 合并两日期区间的间隔，相当于广义的merge()


    return 0;
}
