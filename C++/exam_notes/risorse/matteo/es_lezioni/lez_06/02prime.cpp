#include "utils/in.hpp"
#include "utils/list.hpp"

bool divisible_by_any_of(unsigned long n, list_ulong numbers) {
    //itero sui nodi fino alla fine della lista o fino a che non ne trovo uno 
    //con un valore per cui n è divisibile
    node_list_ulong* iterator;
    bool divisible = false;
    for(iterator = numbers.head; iterator != nullptr && !divisible; iterator = iterator->next)
        divisible = n % iterator->val == 0;

    return divisible;
}

int main() {
    unsigned long N = prompt_for_ulong("inserisci il limite massimo: ", "input invalido!");

    list_ulong primes = construct_list_ulong();

    for(unsigned long i = 2; i <= N; i++)
        if(!divisible_by_any_of(i, primes))
            append_to_list_ulong(primes, i);

    print_list_ulong(std::cout, primes);
}
