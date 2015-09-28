#include <iostream>
#include <thread>

struct my_class{
    my_class(){
      std::cout<< "initialized" << std::endl;
    }
    ~my_class(){
      std::cout << "Deleted" << std::endl;
    }
    int i;
};

thread_local my_class ss;

void do_nothing(){
  std::cout << "do_nothing" << std::endl;
  ss.i = 10;
}

int main(){
  std::thread t1(do_nothing);
  t1.join();
}
