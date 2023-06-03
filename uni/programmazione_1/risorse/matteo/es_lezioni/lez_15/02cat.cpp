#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "l'argomento del programma deve essere un file da leggere" << std::endl;
        return -1;
    }

    std::ifstream file;
    file.open(argv[1]);

    if(file.fail()) {
        std::cout << "Il file non esiste" << std::endl;
        return -1;
    }
    
    char c;
    while(file.get(c)) std::cout << c;

    file.close();
}
