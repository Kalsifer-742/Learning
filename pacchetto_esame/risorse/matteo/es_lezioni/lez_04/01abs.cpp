#include <iostream>
#include "utils/in.hpp"

int main() {
    int a = prompt_for_int("inserisci un numero: ", "input invalido!");
    int b = prompt_for_int("inserisci un altro numero: ", "input invalido!");

    int diff = (a-b)*(a-b >= 0) + (b-a)*(a-b < 0);

    std::cout << "la differenza è " << diff << std::endl;
}
