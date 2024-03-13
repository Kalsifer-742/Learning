# Lezione 19/4/22

## Uguaglianza e identitá: equals

> Durante il confronto tra oggetti devo fare particolare attenzione. Sto confrontando due indirizzi che quindi sono diversi. Devo affidarmi a valori interni o diversamente.

* ==
  * su oggetti controlla gli indirizzi
* equals
  * di base non risolve niente perché é implementata con == ed é pensata per essere overridata
  * la lezione procede a mostrare come implementare per bene un metodo equals pensando a tutti gli imprevisti del caso
  * GetClass
    * che é meno generico di istanceOf che considera le sottoclassi
    * mi permette di controllare se 2 oggetti sono precisamente della stessa classe
* intellij ci puó generare il metodo equals automaticamente

```
@Override
public boolean equals(Object o) {
if (this == o) return true;
if (o == null || getClass() != o.getClass()) return false;
P p = (P) o;
return x == p.x && y == p.y;
}
@Override
public int hashCode() {
return Objects.
hash(x, y);
}
```