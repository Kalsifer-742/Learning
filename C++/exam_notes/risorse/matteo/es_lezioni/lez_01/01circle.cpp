#include <iostream>
#include "utils/in.hpp"

int main() {
    float raggio = prompt_for_float("Inserisci il raggio: ", "Il raggio deve essere un numero reale;");

    const float pi = 3.1415926f;
    float area = pi * raggio * raggio;
    float perimetro = 2.f * pi * raggio;

    std::cout << "A = " << area << "\nC = " << perimetro << std::endl;

    return 0;
}
