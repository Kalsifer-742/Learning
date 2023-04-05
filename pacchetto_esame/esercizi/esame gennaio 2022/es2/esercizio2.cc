#include <iostream>
#include <cstdlib>
#include <cassert>

struct node {
		char info;
		node * next;
};

void dealloca(node *& s) {
		while(s != NULL) {
				node * t = s;
				s = s->next;
				delete t;
		}
}

void stampa_lista(const char * testo, node * s) {
		std::cout << testo;
		for( ; s!= NULL; s=s->next) {
				std::cout << " " << s->info;
		}
		std::cout << std::endl;
}

// Scrivere qui sotto la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie

void compute_lists(const char* string, node*& list1, node*& list2);

// Scrivere qui sopra la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie

int main(int argc, char **argv) {
		if (argc != 2) {
            std::cout << "Usage: " << argv[0] << " \"stringa di caratteri\"" << std::endl;
            exit(1);
		}
		node * s1, * s2;
		std::cout << "La stringa da analizzare e': " << argv[1] << std::endl;

		compute_lists(argv[1], s1, s2);

		stampa_lista("Lista s1:", s1);
		stampa_lista("Lista s2:", s2);
		dealloca(s1);
		dealloca(s2);
}

// Scrivere qui sotto la definizione della funzione compute_lists ed
// eventuali funzioni accessorie

void compute_lists(const char* string, node*& list1, node*& list2)
{
    if(string[0] == '\0')
    {
        list1 = NULL;
        list2 = NULL;
    }
    else if(string[0] >= 'A' && string[0] <= 'M')
    {
        compute_lists(string + 1, list1, list2);
        //trasformazione carattere
        node* tmp = new node{(char)('m' - (string[0] - 'A')), list1};
        list1 = tmp;
    }
    else if(string[0] >= 'N' && string[0] <= 'Z')
    {
        compute_lists(string + 1, list1, list2);
        //trasformazione carattere
        node* tmp = new node{(char)('z' - (string[0] - 'N')), list2};
        list2 = tmp;
    }
    else
    {
        compute_lists(string + 1, list1, list2);
    }
}

// Scrivere qui sopra la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
