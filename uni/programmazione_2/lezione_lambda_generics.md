# Lezione 18/5/22

## Lambda expressions

```java
c.setOnMouseEntered(new EventHandler<MouseEvent>() {
    public void handle(MouseEvent event) {
        System.out.print("Entered");
        c.setFill(Color.RED);
    }
);

    c.setOnMouseEntered((MouseEvent event) -> {
        System.out.print("Entered");
        c.setFill(Color.RED);
    }
);
```

- Inferring the functional interfaces
  - Does the interface have only one abstract (unimplemented) method ?
  - Do the parameters (types) of the lambda expression match the parameters (types) of the single method ?
  - Does the return type of the lambda expression match the return type of the single method ?

## Generics

> chiamati template in c++

- evitiamo cast espliciti che possono creare errori ed evitiamo che si inseriscano oggetti del tipo che non ci interessano in una lista per esempio

```java
class Group<T> { ... //definizione
Group<Student> gs = ... //uso
Group<Tourist> gt = ... //uso
```

- posso usare solo metodi Object perché non conosco i tipi
- posso fare metodi generici
- bisogna fare attenzione ai generics in java perché sono stati aggiunti tardi e quindi sono zucchero sintattico. il compilatore converte le strutture nelle alternative non tipizzate e fa i cast per noi
  - quindi non posso assegnare ad una lista di tipo padre una di tipo figlio
    - un gruppo di studenti non é sottoclasse di un gruppo di persone
- sono implementati tramite type erasure

---

- I generics in Java sono implementati mediante type erasure
  - L’informazione sui parametri tipo viene eliminata dopo i controlli statici
  - Vengono inseriti gli opportuni cast per mantenere i vincoli sul tipo
- Questa scelta mantiene compatibilità con API che non usano generics
  - ma genera una serie di limitazioni

## Wildcard

- È possibile specificare una o più wildcard
  - Rappresentano un tipo non noto
    - `Group<?> g = new Group<Student>();`
  - Non possono essere usate per creare oggetti
    - `Group<?> g = new Group<?>(); // no!`
  - Posso limitare le wildcard
    - `Group<? extends Persona> g = new Group<Student>()`
  - È possibile specificare più di un tipo: se c’è una classe deve essere la prima
    - `Group<? extends Persona & Comparable> g = new Group<Student>(); //studente implementa Comparable`
  - È possibile «limitare» le wildcard anche verso le superclassi
    - `Group<? super Studente> g = new Group<Persona>();`

---

## Limitazioni

- Non posso fare array di generics
  - deriva sempre dall' implementazione
- Generics non si possono usare con instanceof
- I parametri tipo non possono essere tipi primitivi
  - ma con wrapper e autoboxing solitamente si risolve

```java
Object obj = new LinkedList<Long>();
obj instanceof List //true
obj instanceof List<?> //true
obj instanceof List<Long> //error
obj instanceof List<? extends Number> //error
obj instanceof List<? super Number> //error
```

- altri casi particolari...
- [approfondimento sui generics in java](http://www.angelikalanger.com/GenericsFAQ/JavaGenericsFAQ.html)
