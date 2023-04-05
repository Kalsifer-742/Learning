#include <iostream>
#include "utils/in.hpp"

int main() {
    float prezzo = prompt_for_float("Inserisci il prezzo: ", "Il prezzo deve essere un numero reale");
    float iva = prompt_for_float("Inserisci l'IVA in percentuale: ", "L'IVA deve essere un numero reale")/ 100.f;

    float prezzo_al_cliente = prezzo * (1.f + iva);

    std::cout << "il cliente pagera' " << prezzo_al_cliente << " euro" << std::endl;
}
