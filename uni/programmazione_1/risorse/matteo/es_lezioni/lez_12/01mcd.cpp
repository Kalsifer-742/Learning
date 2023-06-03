#include "utils/in.hpp"

int mcd(int m, int n) {
    return 
        m == 0 || n == 0 ? (m+n) :
        m < n ? mcd(n%m, m):
        m > n ? mcd(m%n, n):
        m;//m == n -> mcd = m = n
}

int main() {
    int m = prompt_for_int("inserisci un numero: ", "input invalido!");
    int n = prompt_for_int("inserisci un altro numero: ", "input invalido!");

    std::cout << "mcd(" << m << ", " << n << ") = " << mcd(m, n) << std::endl;
}
