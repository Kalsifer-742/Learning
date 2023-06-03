#include <iostream>
#include "utils/in.hpp"

struct time_h_m_s { int h, m, s; };

time_h_m_s seconds_to_time(long seconds) {
    int s = seconds % 60;
    int m = seconds / 60;
    int h = m / 60;
    m %= 60;

    return { h, m, s };
}

const long seconds_in_a_day = 60 * 60 * 24;

int main() {
    long secs = prompt_for_long_within_range("Inserisci i secondi da mezzanotte: ", "Input invalido!", 0, seconds_in_a_day);

    time_h_m_s t = seconds_to_time(secs);

    std::cout << "sono le " << t.h << ":" << t.m << ":" << t.s << std::endl;
}
