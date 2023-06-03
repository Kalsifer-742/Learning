#include "utils/binary_search.hpp"
#include "utils/quicksort.hpp"
#include "utils/in.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));

    long arr[10];
    for(int i = 0; i < 10; i++)
        std::cout << (arr[i] = std::rand()%10) << " ";
    std::cout << std::endl;

    quicksort(arr, 10);

    for(int i = 0; i < 10; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    long val = prompt_for_long_within_range("inserisci il valore da cercare: ", "input invalido!", 0, 10);

    long pos = binary_search(arr, 10, val);
    if(pos != -1)
        std::cout << val << " e' alla posizione " << pos << std::endl;
    else 
        std::cout << "valore non trovato" << std::endl;
}
