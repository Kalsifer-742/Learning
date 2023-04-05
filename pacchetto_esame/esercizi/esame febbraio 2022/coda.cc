#include <iostream>
using namespace std;

struct node
{
    int value;
    node* previous;
    node* next;
};

struct queue
{
    node* l1_head;
    node* l1_tail;
    node* l2_head;
    node* l2_tail;
};

static queue Q;

// inizializza la coda e altri valori rilevanti, se necessario
void init();
// inserimento di un elemento nella sotto-coda con meno elementi
bool enqueue(int);
// assegna al parametro (passato per riferimento) il valore del primo elemento della sotto-coda del primo sportello
bool firstS1(int&);
// assegna al parametro (passato per riferimento) il valore del primo elemento della sotto-coda del secondo sportello
bool firstS2(int&);
// rimuove il primo elemento della sotto-coda del primo sportello
bool dequeueS1();
// rimuove il primo elemento della sotto-coda del secondo sportello
bool dequeueS2();
// de-inizializza la coda e dealloca eventuale memoria dinamica, se necessario
void deinit();
// stampa a video tutti gli elementi delle due sotto-code
void print();

void delete_list(node*& head);
void print_list(node* head);
int list_length(node* head);

void init()
{
    Q.l1_head = NULL;
    Q.l1_tail = NULL;
    Q.l2_head = NULL;
    Q.l2_tail = NULL;
}

bool enqueue(int val)
{
    if((list_length(Q.l1_head) == 7) && (list_length(Q.l2_head) == 8))
    {
        return false;
    }

    if(list_length(Q.l1_head) < list_length(Q.l2_head))
    {
        node* tmp = new node{val, NULL, NULL};
        if(Q.l1_head == NULL && Q.l1_tail == NULL){
            Q = {tmp, tmp, tmp, tmp};
        }
        else
        {
            tmp->next = Q.l1_head;
            Q.l1_head->previous = tmp;
            Q.l1_head = tmp;
        }
    }
    else
    {
        node* tmp = new node{val, NULL, NULL};
        if(Q.l2_head == NULL && Q.l2_tail == NULL){
            Q = {tmp, tmp, tmp, tmp};
        }
        else
        {
            tmp->next = Q.l2_head;
            Q.l2_head->previous = tmp;
            Q.l2_head = tmp;
        }
    }
    return true;
}

bool dequeueS1()
{
    if(Q.l1_tail == NULL){
        return false;
    }
    else
    {
        int tmp = Q.l1_tail->value;
        node* tmp_node = Q.l1_tail;
        Q.l1_tail = tmp_node->previous;
        delete tmp_node;
        Q.l1_tail->next = NULL;
        return tmp;
    }
    return true;
}

bool dequeueS2()
{
    if(Q.l2_tail == NULL){
        return false;
    }
    else
    {
        int tmp = Q.l2_tail->value;
        node* tmp_node = Q.l2_tail;
        Q.l2_tail = tmp_node->previous;
        delete tmp_node;
        Q.l2_tail->next = NULL;
        return tmp;
    }
    return true;
}

bool firstS1(int& return_value)
{
    return_value = Q.l1_head->value;
    return true;
}

bool firstS2(int& return_value)
{
    return_value = Q.l2_head->value;
    return true;
}

void deinit()
{
    delete_list(Q.l1_head);
    delete_list(Q.l2_head);
}

void delete_list(node*& head){
    if(head == NULL)
    {
        return;
    }
    else
    {
        node* current = head;
        while (current->next != NULL)
        {
            node* tmp = current;
            current = current->next;
            delete tmp;
        }
        delete current;
        head = NULL;
    }
}

void print()
{
    cout << "Prima lista: ";
    print_list(Q.l1_head);
    cout << "Seconda lista: ";
    print_list(Q.l2_head);
}

void print_list(node* head)
{
    node* current = head;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int list_length(node* head)
{
    node* current = head;
    int c = 1;
    while (current->next != NULL)
    {
        c++;
        current = current->next;
    }
    return c;
}