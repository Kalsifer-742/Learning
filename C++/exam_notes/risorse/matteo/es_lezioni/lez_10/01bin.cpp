#include "utils/in.hpp"
#include <climits>
#include <cstring>

const unsigned long_bit_size = CHAR_BIT * sizeof(long);

void to_reverse_binary(long n, char (&bits_str)[long_bit_size+1]);
void print_reversed(std::ostream&, char*);


int main() {
    char bits[long_bit_size+1];
    long n = prompt_for_ulong("inserisci un numero intero", "input invalido!");
    to_reverse_binary(n, bits);
    print_reversed(std::cout, bits);
}

inline void to_reverse_binary_recursive(long n, char* bits) {
    if(n != 0) {
        *bits = '0' + (n & 1);
        to_reverse_binary_recursive(n >> 1, bits + 1);
    }
}

void to_reverse_binary(long n, char(&bits)[long_bit_size+1]) {
    for(int i = 0; i < long_bit_size; i++)
        bits[i] = 0;
    to_reverse_binary_recursive(n, &bits[0]);
}

void print_reversed(std::ostream& output_stream, char* str) {
    unsigned long len = std::strlen(str);
    for(int i = len - 1; i >= 0; i--)
        output_stream << str[i];
}
