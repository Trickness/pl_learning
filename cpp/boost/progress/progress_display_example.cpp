#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <boost/progress.hpp>

using namespace std;

int main(){
    vector<string> v(100);
    v[0] = "sdwad";
    v[1] = "dwad";
    v[2] = "dsadww";
    v[3] = "dwadw";
    v[4] = "sdwad";
    v[5] = "dwad";
    ofstream fs("./test.txt");
    
    boost::progress_display pd(v.size());
    for(auto pos = v.begin(); pos != v.end(); ++pos){
        fs << *pos << endl;
        if(pos->empty()){
            cout << "Null string" << (pos - v.begin()) << endl;
            pd.restart(v.size());
            pd += (pos - v.begin() + 1);
        }else{
            ++pd;
        }
        sleep(1);
    }
    return 0;
}
