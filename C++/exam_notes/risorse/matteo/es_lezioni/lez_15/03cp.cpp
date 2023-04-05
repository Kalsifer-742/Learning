#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    if(argc < 3) {
        std::cout << "l'argomento del programma devono essere il file da leggere e quello da scrivere" << std::endl;
        return -1;
    }

    std::ifstream file;
    file.open(argv[1]);

    if(file.fail()) {
        std::cout << "Il file da leggere non esiste" << std::endl;
        return -1;
    }

    std::ofstream out_file;
    out_file.open(argv[2]);

    char c;
    while(file.get(c)) out_file << c;

    file.close();
    out_file.close();
}
