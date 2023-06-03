#include <fstream>
#include <iostream>
#include <cstring>

bool is_contained_in(const char* str, const char words[][101], int words_len) {
    bool found = false;
    for(int i = 0; i < words_len && !found; i++)
        found = 0 == std::strcmp(str, words[i]);

    return found;
}

int main(int argc, char** argv) {
    if(argc < 3) {
        std::cout << "l'argomento del programma devono essere due file" << std::endl;
        return -1;
    }

    std::ifstream file_1, file_2;
    file_1.open(argv[1]);
    file_2.open(argv[2]);

    if(file_1.fail()) {
        std::cout << "Il primo file da leggere non esiste" << std::endl;
        return -1;
    }

    if(file_2.fail()) {
        std::cout << "Il secondo file da leggere non esiste" << std::endl;
        return -1;
    }

    char parole_file_1[1000][101];
    int parole_file_1_len = 0;
    char parole_file_2[1000][101];
    int parole_file_2_len = 0;
    const char* parole_in_comune[1000];
    int parole_in_comune_len = 0;

    for(int i = 0; i < 1000; i++) {
        char tmp[101];
        if(file_1) {
            file_1 >> tmp;
            if(!is_contained_in(tmp, parole_file_1, parole_file_1_len))
                std::strcpy(parole_file_1[parole_file_1_len++], tmp);
        }
        
        if(file_2) {
            file_2 >> tmp;
            if(!is_contained_in(tmp, parole_file_2, parole_file_2_len))
                std::strcpy(parole_file_2[parole_file_2_len++], tmp);
        }
    }

    file_1.close();
    file_2.close();

    for(int i = 0; i < parole_file_1_len; i++)
        if(is_contained_in(parole_file_1[i], parole_file_2, parole_file_2_len))
            parole_in_comune[parole_in_comune_len++] = parole_file_1[i];

    for(int i = 0; i < parole_in_comune_len; i++)
        std::cout << parole_in_comune[i] << " ";
    std::cout << std::endl;
}
