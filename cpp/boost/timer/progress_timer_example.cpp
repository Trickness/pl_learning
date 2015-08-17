#include <boost/progress.hpp>
#include <iostream>
#include <string>
#include <sstream>  // for stringstream
using namespace std;

int main(){
    {
        boost::progress_timer t;
        int i;
        while(i<10000000) ++i;
    }
    {
        boost::progress_timer t(std::cerr);
        int i;
        while(i<100000000) ++i;
    }
    stringstream ss;
    {
        boost::progress_timer t(ss);
        int i;
        while(i<10000000) ++i;
    }
    cout << ss.str() << endl;
    return 0;
}
