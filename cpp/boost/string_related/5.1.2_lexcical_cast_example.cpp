#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>

using namespace std;

int main(){
    int x       = boost::lexical_cast<int>("100");
    long y      = boost::lexical_cast<long>("200000");
    float pai   = boost::lexical_cast<float>("3.1415926");
    double e    = boost::lexical_cast<double>("2.71828");
    
    double r    = boost::lexical_cast<double>("1.414,x",5);
    cout << r << endl;

    string str = boost::lexical_cast<string>(2323);
    cout << boost::lexical_cast<string>(0.168)  << endl;
    cout << boost::lexical_cast<string>(0x10)   << endl;
    return 0;
}
