#include <iostream>
#include <cstdlib>
#include <ctime>
#include "utils/sort.hpp"
using namespace std;

void print(int* arr, long size);

int main() {
    srand(time(NULL));

    const int size = 10;
    int arr[size];
    
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 10;
    
    print(arr, size);

    bubble_sort(arr, size);

    print(arr, size);
}

void print(int* arr, long size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
