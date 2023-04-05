#include <iostream>
#include "utils/random.hpp"

int main() {
    long arr[10];
    for(int i = 0; i < 10; i++)
        arr[i] = 0;

    fill_with_random_numbers(arr, 10, 0, 100);

    for(int i = 0; i < 10; i++)
        std::cout << arr[i] << " " << std::endl;
}
