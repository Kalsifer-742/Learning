# Lezione 23/3/22

## Costruttori

- costruttore di default
- classi figlie devono invocare il costruttore del padre, questo può essere fatto con l'istruzione `super(...)` che deve essere la prima istruzione del costruttore della classe figlia
- posso chiamare un altro costruttore della stessa classe mettendo come prima istruzione `this(...)`

## Polimorfismo

- Principio di sostituzione di Liskov

  - > Se s è un sottotipo di T, allora variabili di tipo T in un programma possono essere sostitutie da variabili di tipo S senza alterare alcuna proprietà desiderabile del programma
    >
    > ```java
    > Point p = new Point(1,2);
    > p.move(3,4);
    > ---
    > Point p = new NamedPoint(1,2,"A");
    > p.move(3,4);
    > ```
    >

- legame dinamico tra oggetto e tipo, si distingue:
  - dynamic binding (java)
    - tipo statico (deciso a compiletime)
      - il compilatore determina la firma del metodo basandosi sempre sul tipo statico
    - tipo dinamico (deciso a runtime, in java tutte le decisioni sono prese durante l'esecuzione)
      - in caso di overriding la specifica implementazione del metodo la cui firma è stata scelta a compiletime viene determinata a runtime basandosi sul tipo dinamico
    - regola per il binding
      - > il metodo scelto dipende dal tipo dinamico (new ...()) e viene deciso a runtime in questo modo:
    -Si cerca il metodo all'interno della classe del tipo statico
    -Si controlla se il tipo dinamico è una sottoclasse del tipo statico
    -Se è un sottotipo si controlla se è definito un override
    -Se la risposta è si si utilizza l'implementazione della sottoclasse, altrimenti quella della classe padre
  - late binding
  - lazy evaluation
