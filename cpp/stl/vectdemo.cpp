#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> intVector(100);

int main(){
    intVector[99] = 50;
    const auto intIter = find(intVector.begin(), intVector.end(), 50);
    if (intIter != intVector.end())
        cout << "Vector contains value " << *intIter << endl;
    else
        cout << "Vector does not contain 50" << endl;
    return 0;
}

