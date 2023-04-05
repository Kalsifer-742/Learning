#include "utils/in.hpp"
#include "utils/list.hpp"

bool divisible_by_any_of(unsigned long n, list_ulong& numbers) {
    //itero sui nodi fino alla fine della lista o fino a che non ne trovo uno 
    //con un valore per cui n è divisibile
    node_list_ulong* iterator;
    bool divisible = false;
    for(iterator = numbers.head; iterator != nullptr && !divisible; iterator = iterator->next)
        divisible = n % iterator->val == 0;

    return divisible;
}

list_ulong get_primes_up_to(unsigned long n) {
    list_ulong primes = construct_list_ulong();

    for(unsigned long i = 2; i <= n; i++)
        if(!divisible_by_any_of(i, primes))
            append_to_list_ulong(primes, i);
  
    return primes;
}

struct pair_t {
    unsigned long a, b;
    bool is_valid;
};
pair_t get_primes_with_equal_sum(unsigned long n, list_ulong& primes) {
    //define iterators which will iterate the list
    node_list_ulong *iter, *iter2;
    pair_t pair = { 0, 0, false };
    //the first iterator will iterate from the first value in the list up to the first at least as big as n
    for(iter = primes.head; !pair.is_valid && iter && iter->val < n; advance(iter)) {
        //the 2nd iterator will iterate from the value of the first up to the first value that summed with the one pointed to by
        //the other iterator will give a number bigger than n
        for(iter2 = iter; !pair.is_valid && iter2 && (iter->val + iter2->val <= n); advance(iter2)) {
            if(iter->val + iter2->val == n) {
                pair = { iter->val, iter2->val, true };
            }
        }
    }
    
    return pair;
}

int main() {
    unsigned long N = prompt_for_ulong("inserisci il numero in questione: ", "input invalido!");

    list_ulong primes = get_primes_up_to(N);

    pair_t prime_pair = get_primes_with_equal_sum(N, primes);

    if(prime_pair.is_valid)
        std::cout << N << " = " << prime_pair.a << " + " << prime_pair.b << std::endl;
    else
        std::cout << N << " non è esprimibile come somma di due numeri primi" << std::endl;
}
