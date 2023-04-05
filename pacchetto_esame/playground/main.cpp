#include <iostream>
#include <fstream>

using namespace std;

int occurrencies(char word[], char file[]);
bool equal_string(char str1[], char str2[]);
int string_length(const char string[]);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "errato numero di parametri" << endl;
        return 1;
    }
    
    cout << occurrencies(argv[1], argv[2]) << endl;

    return 0;
}

int occurrencies(char word[], char file[])
{
    fstream input;
    input.open(file, ios::in);

    char buffer[256];
    int c = 0;
    while (input >> buffer)
    {
        if (equal_string(word, buffer))
        {
            c++;
        }
    }

    input.close();

    return c;
}

//controlla per la lunghezza della prima parola
bool equal_string(char str1[], char str2[])
{;
    if (string_length(str2) != string_length(str1))
    {
        return false;
    }
    
    bool result = true;
    for (int i = 0; i < string_length(str1); i++)
    {
        if (str1[i] != str2[i])
        {
            result = false;
        }
        
    }
    return result;
}

int string_length(const char string[])
{
    int i;
    for (i = 0; string[i] != '\0'; i++){}
    return i;
}