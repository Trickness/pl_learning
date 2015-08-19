#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

#define VSIZE 24
vector<long> v(VSIZE);

void initialize(long &ri){
    ri = random() - (RAND_MAX / 2);
}

void show(long &ri){
    cout << ri << " ";
}

bool isMinus(const long &ri){
    return (ri<0);
}

class countClass{
    public:
        countClass();
        bool operator()(long &ri);
};

countClass::countClass(){
}

bool countClass::operator()(long &ri){
    return ri<0;
}

int main(){
    srandom(time(NULL));
    for_each(v.begin(),v.end(),initialize);
    cout << "Vecotr of signed long integrers" << endl;
    for_each(v.begin(),v.end(),show);
    cout << endl;


    int count = 0;
    vector<long>::iterator p;
    p = find_if(v.begin(),v.end(),isMinus);     //  断言函数
    while(p != v.end()){
        ++count;
        p = find_if(p+1,v.end(),isMinus);
    }
    cout << "Number of values : " << VSIZE << endl;
    cout << "Negative values  : " << count << endl;

    cout << "Use class to count Negative values" << endl;

    count = 0;
    countClass object;
    p = find_if(v.begin(),v.end(),object);
    while(p != v.end()){
        ++count;
        p = find_if(p+1,v.end(),object);
    }
    cout << "Negative values  : " << count << endl;
    return 0;
}

// 所谓断言函数就是返回Bool值的函数
