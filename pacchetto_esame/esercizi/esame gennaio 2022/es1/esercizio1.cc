#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

int base_conversion(char number[]);
int evaluate(int n1, int n2, char op);

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout << "errato numero di parametri, riprovare!" << endl;
        return 1;
    }

    fstream input;
    fstream output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    if(!input.good() || !output.good())
    {
        cout << "errore nell'apertura dei file, riprovare!" << endl;
        return 1;
    }

    char number1[10];
    char operation;
    char number2[10];
    while (!input.eof())
    {
        input.getline(number1, 10, ' ');
        input >> operation;
        input >> ws;
        input.getline(number2, 10, '\n');
        output << evaluate(base_conversion(number1), base_conversion(number2), operation) << endl;
    }
    
    input.close();
    output.close();

    return 0;
}

int base_conversion(char number[])
{
    int result = 0;
    int base = 17;
    for (int i = strlen(number)-1, j = 0; i >= 0; i--, j++)
    {
        if(number[i] >= 'A' && number[i] <= 'G')
        {
            number[i] -= 'A';
            number[i] += 10;
        }
        else
        {
            number[i] -= '0';
        }
        result += (number[i] * pow(base, j));
    }
    return result;
}

int evaluate(int n1, int n2, char op)
{
    int result;
    switch (op)
    {
    case '+':
        result = n1 + n2;
        break;
    case '*':
        result = n1 * n2;
        break;
    case '^':
        result = pow(n1, n2);
        break;
    
    default:
        break;
    }
    return result;
}