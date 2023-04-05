#include "utils/tree.hpp"
#include <iostream>

int main() {
    tree t = tree_init();

    while(std::cin) {
        long n;
        std::cin >> n;

        insert_ordered(t, n);
    }

    print(t);

    deinit(t);
}

