#include <iostream>
#include "utils/list.hpp"
#include "utils/stack.hpp"
#include "utils/queue.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    using std::puts;

    puts("list:");

    std::srand(std::time(nullptr));

    list l = list_init();
    for(int i = 0; i < 5; i++)
        push_back(l, i);
    print(l);

    for(int i = 5; i < 10; i++)
        push_front(l, i);
    print(l);

    print(reverse(l));

    std::cout << get_length(l) << std::endl;

    print(delete_by_value(l, 5));

    print(delete_by_index(l, 2));
    
    print(sort(l));

    deinit(l);

    l = list_init();
    for(int i = 0; i < 20; i++)
        insert_ordered(l, std::rand() % 20);
    print(l);
    deinit(l);

    puts("stack");

    stack s = stack_init();

    for(int i = 0; i < 5; i++)
        push(s, i);
    
    print(s);

    std::cout << "popping " << pop(s) << " => ";
    print(s);

    deinit(s);

    queue q = queue_init();
    
    for(int i = 0; i < 5; i++)
        enqueue(q, i);
    print(q);

    std::cout << "dequeueing " << dequeue(q) << " => ";
    print(q);
    std::cout << "dequeueing " << dequeue(q) << " => ";
    print(q);

    deinit(q);
}
