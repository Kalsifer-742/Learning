// lettura di intere righe da file
int numeroLinee = 420;
char **stack = new char *[numeroLinee];
for (int i = 0; i < numeroLinee; i++) {
  stack[i] = new char[maxsize + 1];
  myin.getline(stack[i], maxsize);
} // da deallocare con delete []
//////////////////////////////////
int maxLunghezza = 420;
char parola[maxLunghezza];
char **parole = new char *[dim];
for (; !file_a.eof();) {
  parole[i] = new char[strlen(parola) + 1];
  strcpy(parole[i], parola);
  file_a >> parola;
}

// Tips
// + sia la firma che la definizione di una funzione deve avere & nei parametri
