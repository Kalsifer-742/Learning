#include "utils/priority_queue.hpp"
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    priority_queue q = priority_queue_init();
    srand(time(NULL));
    for(int i = 0; i < 5; i++) {
        long priority = rand() % 5 - 1, val = rand() % 50;
        
        printf("enqueueing %i (%i)\n", val, priority);

        enqueue(q, val, priority);
    }
    
    print(cout, q);

    while(!empty(q)) {
        printf("dequeued %i\n", dequeue(q));
    }
}
