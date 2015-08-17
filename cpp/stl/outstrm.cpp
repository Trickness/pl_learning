#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iterator> // for std::ostream_iterator

using namespace std;

void Display(vector<int>& v, const char *s){
    cout << endl << s << endl;
    copy (v.begin(), v.end(), ostream_iterator<int>(cout,"\t"));
    cout << endl;
}

int main(){
    // seed the random number generator
    srandom(time(NULL));

    // construct vector and fill with random integer values
    vector<int> collection(10000);
    for (int i = 0; i < 10000; ++i)
        collection[i] = random() % 10000;

    // Display , sort and redisplay
    Display(collection,"Before sorting");
    sort(collection.begin(),collection.end());
    Display(collection,"After sorting");
    return 0;
}
