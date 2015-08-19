#include <iostream>
#include <algorithm>
#include <functional>
#include <list>

using namespace std;

//  Data
int iArray[10] = {1,2,3,4,5,6,7,8,9,10};
list<int> aList(iArray,iArray + 10);

int main(){
    int k = count_if(aList.begin(),aList.end(),bind1st(greater<int>(),8));  // 小于8
    // the same as
    //      count_if(aList.begin(),aList.end(),func))
    //
    //      func(int &x)    return 8 > x;
    //  k = count_if(aList.begin(),aList.end(),not1(bind2nd(greater<int>(),8)));    // 不大于8
    cout << "Number elements < 8 == " << k << endl;
    return 0;
}
