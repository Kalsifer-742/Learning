#include <iostream>
#include <fstream>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;


void stampaAlbero(albero radice, int spazio=0);
int load_values(char input_file[], int*& arr);
nodo* create_balanced_tree_from_array(int array[], int start, int end);
void bubble_sort(int arr[], int DIM);
void delete_tree(nodo*& root);
void print_array_iterative(int array[], int DIM);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "numero di input errato, riprovare" << endl;
        return 1;
    }

    int* array = NULL;
    int DIM = load_values(argv[1], array);
    cout << "-----" << endl;
    cout << DIM << endl;
    cout << "-----" << endl;
    print_array_iterative(array, DIM);
    cout << "-----" << endl;
    bubble_sort(array, DIM);
    print_array_iterative(array, DIM);
    
    albero albero = create_balanced_tree_from_array(array, 0, DIM-1);
    
    stampaAlbero(albero);
    
    delete[] array;
    delete_tree(albero);
    
    return 0;
}

void print_array_iterative(int array[], int DIM)
{ 
    for (int i = 0; i < DIM; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int load_values(char input_file[], int*& arr)
{
    fstream input;
    int DIM = 0;
    int c = 0;
    int buffer;

    input.open(input_file, ios::in);
    if(!input.good())
    {
        cout << "errore nell'apertura del file, riprovare" << endl;
    }

    while(input >> buffer)
    {
        c++;
    }
    cout << c << endl;
    cout << "-----" << endl;

    DIM = c;
    arr = new int[c];
    c = 0;
    input.clear();
    input.seekg(0);

    while (input >> buffer)
    {
        cout << buffer << " ";
        arr[c] = buffer;
        cout << arr[c] << endl;
        c++;
    }

    input.close();

    return DIM;
}

nodo* create_balanced_tree_from_array(int array[], int start, int end)
{
    if(start > end)
    {
        return NULL;
    }
    
    int middle = (start + end) / 2;
    nodo* root = new nodo{array[middle], NULL, NULL};
    root->left = create_balanced_tree_from_array(array, start, middle - 1);
    root->right = create_balanced_tree_from_array(array, middle + 1, end);

    return root;
}

void delete_tree(nodo*& root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        root = NULL;
    }
}

void bubble_sort(int arr[], int DIM)
{
	int tmp;
	
	bool swapped = true;	
	while(swapped){
		swapped = false;
		for(int i = 0; i < DIM-1; i++){
			if(arr[i] > arr[i+1]){
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				swapped = true;
			}
		}	
	}
}

/** Stampa dell'albero */
void stampaAlbero(albero radice, int spazio){
    if (radice != NULL) {
        spazio ++;

        stampaAlbero(radice->right, spazio);

        for (int i = 1; i < spazio; i++) {
            cout<<"\t";
        }
        cout<<radice->value<<"\n";

        stampaAlbero(radice->left, spazio);
    }
}