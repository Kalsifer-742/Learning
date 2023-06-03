#include "utils/stack.hpp"
#include <iostream>
#include <cstring>

int main() {
    char parola[101];

    std::cin.getline(parola, 100);

    int parola_len = std::strlen(parola);

    stack s = stack_init();

    for(int i = 0; i < parola_len/2; i++)
        push(s, parola[i]);

    bool palindroma = true;
    for(int i = parola_len/2 + parola_len%2; i < parola_len; i++)
        if(pop(s) != parola[i])
            palindroma = false;

    std::cout << "la parola " << (palindroma ? "" : "non ") << "e' palindroma" << std::endl;
}
