#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

struct occurrence
{
    char* value;
    int count;
};

void occurencies(char input_file[], char output_file[]);
void initialize(occurrence array[]);
bool is_odd(int value);
void print(occurrence array[]);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "errato numero di parametri, riprovare" << endl;
        return 1;
    }
    
    occurencies(argv[1], argv[2]);

    return 0;
}

void occurencies(char input_file[], char output_file[])
{
    fstream input, output;
    input.open(input_file, ios::in);
    output.open(output_file, ios::out);
    int DIM = 100;

    if(!input.good() || !output.good())
    {
        cout << "errore nell'apertura dei file, riprovare" << endl;
    }

    occurrence occurrencies[DIM];
    initialize(occurrencies);

    char buffer[DIM];
    int tmp = 0;
    while (input >> buffer)
    {
        tmp = atoi(buffer);

        if (is_odd(tmp))
        {
            for (int i = 0, j = 0; i < DIM; i++)
            {
                if (occurrencies[i].value == NULL)
                {
                    occurrencies[i].value = buffer;
                }
                else if (strcmp(buffer, occurrencies[i].value) == 0)
                {
                    occurrencies[i].count++;
                }
            }   
        }     
    }

    for (int i = 0; i < DIM; i++)
    {
        if (occurrencies[i].value != NULL)
        {
            output << occurrencies[i].value << ": " << occurrencies[i].count << endl;
        }
    }
    
    input.close();
    output.close();
}

void initialize(occurrence array[])
{
    for (int i = 0; i < 100; i++)
    {
        array[i].value = NULL;
        array[i].count = 0;
    }
    
}

bool is_odd(int value)
{
    if (value % 2 == 0)
    {
        return false;
    }
    return true;
}