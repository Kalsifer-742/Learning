#include <iostream>
#include <iomanip>
#include <cstring>

int main() {
    size_t str_max_size = 64;
    char str[str_max_size];
    std::cin >> std::setw(str_max_size-1) >> str;
    size_t str_len = std::strlen(str);
    int decimal_value = 0;

    for(int i = 0; i < str_len; i++) {
        if(str[i] == '1') {
            int significance = str_len - i - 1;
            decimal_value |= (1 << significance); //set the corresponding bit
        }
    }

    std::cout << decimal_value << std::endl;
}
