# Lezione 22/03/22

- `this` per riferirmi ad attributi o metodi della mia classe o all`istanza

## Ereditarietá e Polimorfismo

- keyword `extends`
  - `Class Cane extends Mammifero {}`
- la sottoclasse ereditá tutti gli attributi e tutti i metodi della superclasse
- java non supporta l'eredità multipla
- una classe se non diversamente specificato eredità la classe Object, _radice dell'intera gerarchia_
- Object fornisce alcuni importanti metodi:
  - `equals(Object)`
  - `finalize()` - deprecata in teoria
  - `toString()`
- overriding
  - consiste nel redefinire i metodi della superclasse
- `super`
  - é una pseudo variabile utilizzata per riferire metodi della superclasse
- costruttori
  - non vengono ereditati
  - tramite `super` possono essere chiamati i costruttori della superclasse. Va messa come prima istruzioni. Se il programmatore non lo fa esplicitamente il compilatore inserisce del codice che chiama il costruttore di default (senza parametri) della superclasse.
- UML
  - esiste
- Overloading
  - possono esistere più metodi con lo stesso nome e diverse implementazioni che si distinguono per numero e/o tipo di parametri
  - il valore di ritorno non permette di distinguere due metodi, no overloading sul tipo di ritorno

- overloading vs overriding
	- a volte avviene uno a volte l'altro dipende dai casi e tipi statici e dinamici (guarda slide)

- costruttore di default
  - esiste e viene creato
  - MA se la classe padre definisce un costruttore con parametri non può essere creato un costruttore di default. Se il programmatore specifica un costruttore il linguaggio non introduce altro
```java
class A {
    int x;
    int y;
    A(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class B extends A {
    //il compilatore aggiunge ma A() non esiste e non viene creato perchè esiste già A(int x, int y)
    /*
    B(){
        super();
    }
    */

   //anche scrivendo non funzionerebbe perchè il compilatore trasforma in B(){super()}
   //B(){}
}

//NON compila
```

- keyword
	- final
		- definisce una classe o un metodo come non più modificabile (o una variabile)
	- private
		- visibile solo internamente alla classe
	- protected
		- visibile solo dalle classi dello stesso package e dalle sottoclassi
