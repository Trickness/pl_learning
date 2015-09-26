#include <iostream>
#include <memory>
#include <string>
#include "ring_queue.h"

using namespace std;

int main(){
    auto queue_writer = make_ring_queue_writer<int>(10);
    return 0;
}

