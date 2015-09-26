#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> int_vector = {10,12,23,24,43};
    for (auto &i : int_vector){
        cout << i << endl;
    }
    return 0;
}
