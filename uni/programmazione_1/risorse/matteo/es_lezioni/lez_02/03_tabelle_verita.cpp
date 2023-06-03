#include <iostream>

int main() {
    std::cout << "\tAND\t\t\t\tOR\t\t\t\tXOR" << std::endl;
    for(int i = 0; i < 4; i++) {
        bool a = i & 2, b = i & 1;

        std::cout 
            << a << "\t" << b << "\t" << (a&&b) << "\t\t" 
            << a << "\t" << b << "\t" << (a||b) << "\t\t"
            << a << "\t" << b << "\t" << (a!=b) << std::endl;
    }
}
