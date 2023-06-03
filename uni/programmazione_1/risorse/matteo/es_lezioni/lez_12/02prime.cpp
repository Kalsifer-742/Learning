#include "utils/in.hpp"
#include "utils/list.hpp"

unsigned long get_first_divisor(unsigned long n, list_ulong numbers) {
    //itero sui nodi fino alla fine della lista o fino a che non ne trovo uno 
    //con un valore per cui n è divisibile
    node_list_ulong* iterator;
    unsigned long divisor = 0;
    for(iterator = numbers.head; iterator && !divisor; advance(iterator))
        if(n % iterator->val == 0)
            divisor = iterator->val;

    return divisor;
}

list_ulong get_primes_up_to(unsigned long n) {
    list_ulong primes = construct_list_ulong();
                                           
    for(unsigned long i = 2; i <= n; i++)   
        if(!get_first_divisor(i, primes))   
            append_to_list_ulong(primes, i);

    return primes;
}

list_ulong get_prime_factors(unsigned long n, list_ulong primes) {
    unsigned long div = get_first_divisor(n, primes);
    if(!div) return construct_list_ulong();

    list_ulong prime_factors = get_prime_factors(n/div, primes);

    return append_to_list_ulong(prime_factors, div);
}

int main() {
    unsigned long N = prompt_for_ulong("inserisci il numero da fattorizzare: ", "input invalido!");

    list_ulong primes = get_primes_up_to(N);
    
    list_ulong factors = get_prime_factors(N, primes);

    destruct_list_ulong(primes);

    print_list_ulong(std::cout, factors);

    destruct_list_ulong(factors);
}
