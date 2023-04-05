#include <iostream>
#include "utils/in.hpp"

bool is_valid_time(long h, long m, long s) {
    return h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60;
}

int main() {
    long h, m, s;

    bool value_is_set = false;
    while(!value_is_set) {
        std::cout << "inserisci l'ora: " << std::flush;
        std::cin >> h >> m >> s;
        value_is_set = std::cin && is_valid_time(h, m, s);
        if(!value_is_set) {
            std::cout << "l'ora deve essere nel formato hh mm ss e deve essere un orario valido" << std::endl;
            recover_stream_after_error(std::cin);
        }
    }

    m += 60*h;
    s += 60*m;

    std::cout << "secondi da mezzanotte: " << s << std::endl;
}
