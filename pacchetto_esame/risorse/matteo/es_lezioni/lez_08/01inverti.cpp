#include "utils/in.hpp"

int main() {
    int n = prompt_for_int_within_range("inserisci un numero naturale da invertire", "input invalido!", 0);
    
    do {
        std::cout << n % 10;
        n /= 10;
    } while(n != 0);
    std::cout << std::endl;
}
