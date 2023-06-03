# Lezione 10/5/22

#### Errore tipico

```java
public class PratoFiorito extends Application {
  public PratoFiorito(Input input) {
  ...
  }
  @Override
  public void start(Stage stage) {
    Input input = new Input();
    PratoFiorito pf = new PratoFiorito(input);
...

//Non create MAI un costruttore non vuoto di una classe che estende Application
//Non istanziate MAI una classe che estende Application
```

## Eventi pressione tasti

- `KEYTYPED`
  - `e.getCharacter().equals("W")`

- `KEYPRESSED` e `KEYRELEASED`
  - `e.getCode() == KeyCode.W`

---

- `fireEvent()`
  - utile per evitare di riscrivere lo stesso codice
  - utilizzo l' eventhandler per l' evento specifico dell' oggetto su cui viene chiamato

```java
...
if (keyEvent.getCharacter().equals("u”)) {
  b1.fireEvent(new ActionEvent());
...
```

## Propagazione eventi

- Focus
  - finestra/componente selezionato

---

- Propagazione gerarchica degli eventi
  - l' evento scende gerarchicamente per poi risalire allo stesso modo
    - capturing (filters)
      - gli eventi scendono la catena gerarchica fino a raggiungere il componente che li ha creati
    - bubbling (handlers)
      - gli eventi risalgono la catena gerarchica

> voglio che funzioni cosí perché per esempio in una calcolatrice posso creare un handler sul contenitore dei tasti che se scritto opportunamente in modo generico interecetta gli eventi dei tasti. Altrimenti dovrei scrivere un sacco di handler o assegnare lo stesso handler a tutti i tasti

- TARGET
  - mi dice chi ha generato l' evento (o perché é stato generato un evento)
- SOURCE
  - mi dice chi sta gestendo l' evento

---

> posso bloccare gli eventi nella catena

```java
t.consume()
```

---

```java
...
EventHandler<KeyEvent> keyEventHandler =
  new EventHandler<KeyEvent>(){
  public void handle(KeyEvent keyEvent) {
    System.out.println(keyEvent.getSource() + " =>" + keyEvent.getTarget());

    switch (keyEvent.getCharacter()){
      case "u":
      case "U":
        b1.fireEvent(new ActionEvent()); b1.requestFocus();
        break;
      case "d":
      case "D":
        b2.fireEvent(new ActionEvent()); b2.requestFocus();
        break;
    }
  };
...
stage.addEventHandler(KeyEvent.KEY_PRESSED,keyEventHandler);
...
```