#include "utils/in.hpp"

int main() {
    float temp_fahrenheit = prompt_for_float("Inserisci la temperatura in gradi Fahrenheit: ", "La temperatura deve essere un numero reale");
    float temp_celsius = (temp_fahrenheit - 32.f) / 1.8f;

    std::cout << temp_fahrenheit << "F = " << temp_celsius << "C" << std::endl;
}
