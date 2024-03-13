# Lezione 12/4/22

## Eventi in JavaFX

- concetto di abbonati
- event handler
- gererchia degli eventi
- multipli handler = multipli subscriber credo

> #### Classi interne
>
> - visibili solo all'interno dello scope in cui vengono definite

- handler anonimi (funzione dichiara al momento)

#### Convenience methods

```java
btn.setOnAction(this);
//btn.addEventHandler(ActionEvent.ACTION, this);
```

- utili per scrivere codice piú conciso
- definiti per gli eventi piú comuni
- usati assieme a listener anonimi per ridurre la verbositá

#### Listenere e generics

```java
EventHandler<ActionEvent>
```

- cioé si esistono e si puó fare
