#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>

typedef struct List {
		int info;
		struct List * next;
} List;

const int MAXNUM = 50;

void do_print(const List *l);
void stampa_list(const List * l, const char * prefix);
List * create_random_list(int i = 0);
void dealloca(List * & l);

// ---------------------------------------------------------------
// Inserire qui sotto la dichiarazione della funzione compute_list

void compute_list(List* l, List*& s1, List*& s2); 

// Inserire qui sopra la dichiarazione della funzione compute_list
// ---------------------------------------------------------------

// NON modificare il main
int main(int argc, char ** argv) {
		// Non modificare il main
		if (argc != 1) {
				std::cerr << "Usage: " << argv[0] << std::endl;
				exit(1);
		}

		int seed = 0;
		// Inizializzare random_seed a true per un comportamento random
		bool random_seed = false;
		if (random_seed)
				seed = time(NULL);

		srand(seed);
		List * l = create_random_list();
		stampa_list(l, "Lista iniziale");
		List * l1, *l2;
		compute_list(l, l1, l2);
		stampa_list(l1, "Lista l1");
		stampa_list(l2, "Lista l2");
		dealloca(l);
		dealloca(l1);
		dealloca(l2);
}

// ---------------------------------------------------------------
// Inserire qui sotto la definizione della funzione compute_list

void compute_list(List* l, List*& s1, List*& s2)
{
    if (l == NULL)
    {
        s1 = NULL;
        s2 = NULL;
    }
    else if ((l->info % 2 == 0) && (l->info % 3 != 0))
    {
        compute_list(l->next, s1, s2);
        List* tmp = new List{l->info, s2};
        s2 = tmp;
    }
    else if(l->info % 3 == 0)
    {
        compute_list(l->next, s1, s2);
        List* tmp = new List{l->info, s1};
        s1 = tmp;
    }
    else
    {
        compute_list(l->next, s1, s2);
    }
}

// Inserire qui sopra la definizione della funzione compute_list
// ---------------------------------------------------------------

// ---------------------------------------------------------------
// NON MODIFICARE IL CODICE SOTTOSTANTE
// ---------------------------------------------------------------
// Non modificare questa funzione
void do_print(const List *l) {
		if (l != NULL) {
				std::cout << " \"" << l->info << "\"";
				do_print(l->next);
		}
}
// Non modificare questa funzione
void stampa_list(const List * l, const char * prefix) {
		std::cout << prefix << " :";
		do_print(l);
		std::cout << std::endl;
}

// Non modificare questa funzione
List * create_random_list(int i) {
		List * res = NULL;
		if (i < MAXNUM) {
				res = new List{rand() % MAXNUM, create_random_list(++i)};
		}
		return res;
}

// Non modificare questa funzione
void dealloca(List * & l) {
		if (l != NULL) {
				List * n = l;
				dealloca(l->next);
				delete n;
		}
}
