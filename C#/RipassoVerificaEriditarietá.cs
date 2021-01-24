using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RipassoVerifica
{
    //argomenti: information hiding, ereditarietá, polimorfismo, binding dinamico

    /* 
     * Information hiding: si intende il livello di protezione degli attributi e quindi la loro visibilitá
     * keyword: private(default), public e protected.
     * public --> visibile a tutti (UML +)
     * private --> visibile solo all interno della classe (UML -)
     * protected --> visibile all interno della classe e nelle classi figlie (UML #)
     */


    class Program
    {
        abstract class Figura //classe di tipo asbtract (basta un solo metodo abstract perché tutta la classe debba esserlo)
        {
            //é una normale classe da usare come stampino
            private int x; 
            abstract public void Metodo(); //scrivo la firma del motodo, ma non lo implemento (sono obbligato ad implementarlo nella classe figlia)
        }
        class Rettangolo:Figura //classe madre di quadrato
        {
            public int a;
            private int b;
            protected int c;

            public Rettangolo(int a, int b, int c)
            {
                this.a = a; //this si riferisce alla classe corrente
                this.b = b;
                this.c = c;
            }

            public override void Metodo() //per implementare un metodo uso override (letteralmente lo sovrascrivo)
            {
                //implementazione del metodo
            }

            public virtual void Area() //virtual serve a fare in modo che il metodo possa essere riscritto (override)
            {
                //codice
            }
        }
        class Quadrato:Rettangolo //classe figlia di rettangolo
        {
            private int d;

            public Quadrato(int a, int b, int c, int d):base(a, b, c) //chiama il costruttore della classe madre
            {
                this.d = d;
            }          

            public override void Area() //nuovo metodo ma con lo stesso nome di quello della classe padre
            {
                //codice del nuovo metodo
                c = 0; //accedo all'attributo protected della classe madre
            }
        }
        static void Main(string[] args)
        {
            Rettangolo A = new Rettangolo(1, 2 ,3); //istanzio oggetto classe Rettangolo

            Quadrato B = new Quadrato(1, 2, 3, 4); //istanzio oggetto classe Quadrato

            A.a = 2; //attributo pubblico
            A.Metodo(); //metodo ereditato da figura e implementato
            A.Area();

            B.Area(); //metodo ereditato (con lo stesso nome della classe a) e sovrascritto (quindi fa qualcosa di diverso)
            
            A = (Rettangolo)B; /*
                                *upcasting (sempre permesso) (non perdo informazioni, cioé: "A is Quadrato" restituisce true.
                                *si puó dire che non si dimentica cos'era prima (é bruttussimo ma rende l'idea)
                               */
            
            B = (Quadrato)A; //downcasting (non sempre permesso) in caso di errore crea un eccezione ed il programma va in crash

            if(A is Rettangolo)//is mi dice se a é di tipo Rettangolo
            {
                //codice
            }

            B = A as Quadrato; //as in caso di errore fa diventare A null e quindi non genera eccezioni
        }
    }
}
