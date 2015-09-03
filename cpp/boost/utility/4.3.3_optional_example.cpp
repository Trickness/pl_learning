#include <iostream>
#include <boost/optional/optional.hpp>
#include <boost/none.hpp>

using namespace std;

int main(){
    boost::optional<int> op0;   //  未初始化的optional对象
    boost::optional<int> op1(boost::none);

    assert(!op0);
    assert(op0 == op1);

    assert(op1.get_value_or(253) == 253);
//    cout << op1.get_value_or_eval([](){return 876;}) << endl;
    return 0;
}
