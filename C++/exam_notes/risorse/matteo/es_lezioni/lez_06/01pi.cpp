#include "utils/in.hpp"
#include <cmath>

int main() {
    unsigned long N = prompt_for_ulong("quante iterazioni della serie? ", "input invalido!");

    double series = 0;
    for (unsigned long i = 1; i <= N; i++)
        series += 1./(double)(i*i);
    
    double pi = std::sqrt(series*6);

    std::cout << "pi = " << pi << std::endl;
}
