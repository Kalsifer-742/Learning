# Lezione 5/4/22

## Casting

- conversioni forzata tra tipo di riferimento
- possibile forzare conversione da un tipo T ad un suo sottotipo T1 se il tipo dinamico é un sottotipo di T1
- upcasting e downcasting

```java
Object o = new AutomobileElettrica(); //UPCASTING (conversione implicita, polimorfismo, regola is-a)
Automobile a = o;   // errato, Object non è un
                    // sottotipo di Automobile
Automobile a = (Automobile) o;  // corretto (casting) DOWNCASTING
```

- `istanceof`
  - mi permette di determinare il tipo dinamico di un oggetto

## Gestione degli errori

```java
try 
{
    //codice rischioso che potrebbe generare un errore
    int z = Integer.parseInt(inputString);
    System.out.println("input valido!");
} 
catch
{
    //codice da eseguire se si verifica un errore
    System.out.println("input non valido!");
}
finally
{
    //codice da eseguire in ogni caso
}
/*
    The finally block always executes when the try
    block exits. This ensures that the finally block is
    executed even if an unexpected exception
    occurs. But finally is useful for more than just
    exception handling — it allows the programmer
    to avoid having cleanup code accidentally
    bypassed by a return, continue, or break.
    Putting cleanup code in a finally block is always
    a good practice, even when no exceptions are
    anticipated.
*/
```
