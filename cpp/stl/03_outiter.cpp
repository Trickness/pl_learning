#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int iarray[10] = {1,2,3,4,5,6,7,8,9,10};

vector<int> vint(10);

int main(){
    auto outputIterator = vint.begin();
    copy(iarray,iarray+10,outputIterator);
    while (outputIterator != vint.end()){
        cout << *outputIterator << endl;
        ++outputIterator;
    }
    return 0;
}
