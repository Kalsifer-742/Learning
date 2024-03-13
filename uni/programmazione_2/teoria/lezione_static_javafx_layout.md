# Lezione 20/4/22

## Static

* modificatore che associa alla classe e non all'oggetto
* valore condiviso tra le istanze
* metodi chiamabili senza creare un istanza
* limiti di variabili e metodi statici

> breve infarinatura, l'argomento verrá trattato piú a fondo successivamente

## JavaFX

* layout
  * rende le pagine responsive
  * il layout decide come vengono disposte le cose

> procede a spiegare lentamente come funziona FX, come disporre elementi, come creare cose di cui non esistono le primitive. Esplora vari container ed elementi.

```
GridPane
/**
* implementazione generale del metodo per trovare quale elementi si trovi
* in posizione i,j in un GridPane.
* @param dp il GridPane in cui cercare
* @param i riga
* @param j colonna
* @return l'elemento trovato
*/
Node getElementAt(GridPane gp, int i, int j) {
for (Node x :gp. getChildren()) {
if ((GridPane.getRowIndex(x) == i) &&
(GridPane.getColumnIndex(x) == j)) {
return x;
}
}
return null;
}
```

* accenno a model, view e controller

> tutta sta roba assomiglia all'interfaccia con c# e contemporaneamnete ad html e css

* Translate
  * utile per spostare elementi rispetto alla loro posizione definita dal layout

> propone di divertirsi e sperimentare. sarebbe buona cosa per l'esame tentare di cacciare un pong