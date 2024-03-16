# Lezione

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
  - risale tutta la gerarchia finchè non lo trova
- costruttori
  - non vengono ereditati
  - tramite `super` possono essere chiamati i costruttori della superclasse. Va messa come prima istruzioni.
  - costruttore di default
    - Se la classe definisce un costruttore con parametri non può essere creato un costruttore di default. Se il programmatore specifica un costruttore il linguaggio non introduce altro.
  ```java
  class A {
    int x;

    // A() {
    //   this.x = 0;
    // }
    A(int x) {
      this.x = x;
    }
  }

  class B extends A {
    B() { super(); } //il compilatore inserisce questa riga
  }
  ```
  - ^^^ se il programmatore non specifica un costruttore per la sottoclasse il compilatore chiama il costruttore di default della superclasse.
  Se il costruttore di default della superclasse non è definito il codice non può compilare.
- UML
  - esiste
- Overloading
  - possono esistere più metodi con lo stesso nome e diverse implementazioni che si distinguono per numero e/o tipo di parametri
  - il valore di ritorno non permette di distinguere due metodi, no overloading sul tipo di ritorno

- overloading vs overriding
	- a volte avviene uno a volte l'altro dipende dai casi e tipi statici e dinamici (guarda slide)

- keyword
	- final
		- definisce una classe o un metodo come non più modificabile (o una variabile)
	- private
		- visibile solo internamente alla classe
	- protected
		- visibile solo dalle classi dello stesso package e dalle sottoclassi
