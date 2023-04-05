#include <iostream>
#include "utils/in.hpp"

int main() {
    int base = prompt_for_int("inserisci la base: ", "input invalido!");
    int max_exp = prompt_for_int_within_range("inserisci l'esponente massimo: ", "input invalido!", 1);
    
    int result = 1;

    for(int exp = 1; exp <= max_exp; exp++) {
        result *= base;
        std::cout << base << " ^ " << exp << " = " << result << std::endl;
    }
}
