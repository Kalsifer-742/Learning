# Lezione 24/05/22

## Clonazione

```java
protected Object clone()
    throws CloneNotSupportedException
//Creates and returns a copy of this object. The precise meaning of "copy" may depend on the class of the object.
```

- the expression: `x.clone() != x` will be `true`,
- and that the expression: `x.clone().getClass() == x.getClass()` will be `true`, but these are not absolute requirements.
- While it is typically the case that: `x.clone().equals(x)` will be `true`, this is not an absolute requirement.

```java
class P implements Cloneable {
    ...
    public Object clone(){
        try {
            return super.clone(); // copia bit a bit
        } catch (CloneNotSupportedException e) {
            System.err.println("Implementation error");
            System.exit(1);
        }
        return null; //qui non arriva mai
    }
}
```

> se clono un oggetto che contiene un array clono il puntatore allo stesso array. Non viene creato un nuovo array uguale perché faccio una copia bit a bit se non specificato diversamente

---

- shallow copy
- deep copy

---

> non so perché ha fatto una digressione sulla clonazione degli oggetti in c++