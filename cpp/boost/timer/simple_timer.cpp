#include <iostream>
#include <boost/timer.hpp>
#include <cstdlib>
#include <cstring>

using namespace std;
using namespace boost;

int main(){
    timer t;
    sleep(2);   // There's no influences on timer
    int i = 0;
    while(i < 10000000) ++i;    //  There's influence
    cout << "Max timespan: " << t.elapsed_max()/3600 << " h" << endl;
    cout << "Min temespan: " << t.elapsed_min() << " s" << endl;
    cout << "Now time elapsed: " << t.elapsed() << " s" << endl;
    return 0;
}
