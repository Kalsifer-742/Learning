# Lezione 4/26/22

## Hashcode
> spiega cosa sia l' hash

> perché serve fare l'override di hashcode oltre che di equals:

- [geekforgeeks](https://www.geeksforgeeks.org/override-equalsobject-hashcode-method/)
- [stackoverflow](https://stackoverflow.com/questions/2265503/why-do-i-need-to-override-the-equals-and-hashcode-methods-in-java)

> hashcode viene chiamato prima di equals per efficienza. con equals vado sul sicuro e non sbaglio mai. insomma ricordarsi di implementare quello che serven

## Comparable

> Definisce un unico metodo
`int compareTo(Object o)`
che ritorna
- un intero negativo se this è minore di o
- un intero positivo se this è maggiore di o
- 0 se this è uguale a o

## Comparator

> Definisce un unico metodo
`int compare(Object o1, Object o2)`
che permette di delegare il confronto ad una classe separata. Definisco una classe per ogni metodo di comparazione necessario. La classe implementa solo il metodo compare. É una classe ausiliara piccolissima