#include <cstdlib>
#include "utils/in.hpp"

int main() {
    int n = prompt_for_int_within_range("inserisci il numero di righe", "input invalido!", 0, 15);
    int m = prompt_for_int_within_range("inserisci il numero di colonne", "input invalido!", 0, 15);

    

    int (*mat_single_alloc)[3] = new int[n][3];

    delete[] mat_single_alloc;



    int** mat_roveri = new int*[n];
    for(int i = 0; i < n; i++)
        mat_roveri[i] = new int[m];

    for(int i = 0; i < n; i++)
        delete[] mat_roveri[i];
    delete[] mat_roveri;

    //compiled but untested
    int** mat = new int*[n];
    mat[0] = new int[m*n];
    for(int i = 1; i < n; i++)
        mat[i] = mat[0] + m*i;

    delete[] mat[0];
    delete[] mat;
}
