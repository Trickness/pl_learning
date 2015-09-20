#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "ring_queue.h"

using namespace std;

int main(){
    ring_queue<int> s(10);
    for(int i=0;i<10;i++)
        s.push(i);
    for(int i=0;i<5;i++){
        auto t = s.fetch();
        if(t != nullptr)
            cout << *t << endl;
        else
            cout << "t is none" << endl;
    }
    for(int i=0;i<5;i++)
        s.push(i);
    for(int i=0;i<10;i++){
        auto t = s.fetch();
        if(t != nullptr)
            cout << *t << endl;
        else
            cout << "t is none" << endl;
    }
    return 0;
}

