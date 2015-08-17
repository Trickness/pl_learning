#include <iostream>
#include <stdlib.h> //  Need random(), standom()
#include <time.h>   //  Need  time()
#include <algorithm>//  Need random_shuffle()
#include <vector>
#include <functional>   // Need ptr_fun()
#include <iterator> //  Need ostream_iterator

using namespace std;

// Data to randomize

int iArray[10] = {1,2,3,4,5,6,7,8,9,10};
vector<int> v(iArray,iArray+10);

// Function prototypes
void Display(vector<int>& vr, const char *s){
    cout << endl << s << endl;
    copy(vr.begin(),vr.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
}

unsigned int RandInt(const unsigned int n){
    return random() % n;
}

int main(){
    srandom(time(NULL));
    Display(v,"Before shuffle:");
    auto ptr_RandInt = ptr_fun(RandInt);
    random_shuffle(v.begin(),v.end(),ptr_RandInt);

    Display(v,"After shuffle:");
    return 0;
}
