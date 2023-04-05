#include <iostream>
#include <cstring>

bool validate(int argc, char** argv) {
    if(argc != 4) 
        return false;
    if(std::strlen(argv[2]) != 1) 
        return false;
    char op = argv[2][0];
    if(op != '+' && op != '-' && op != '*' && op != '/') 
        return false;

    return true;
}

struct operands_and_operation {
    int a,b;
    char op;
};

operands_and_operation parse_argv(char** argv) {
    return { std::atoi(argv[1]), std::atoi(argv[3]), argv[2][0] };
}

int calculate(operands_and_operation o) {
    switch(o.op) {
        case '+':
            return o.a+o.b;
        case '-':
            return o.a-o.b;
        case '*':
            return o.a*o.b;
        case '/':
            return o.a/o.b;
    }
}

int main(int argc, char** argv) {
    for(int i = 0; i < argc; i++) std::cout << argv[i] << " ";
    std::cout << std::endl;
    if(!validate(argc, argv))
        std::cout << "input invalido!" << std::endl;
    else
        std::cout << calculate(parse_argv(argv)) << std::endl;
}
