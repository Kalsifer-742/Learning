# Lecture 20/03/24

## Trapping

lavora a livello di istruzione della cpu. guardo l'istruzione in quale ring vuole eseguire. non mi interessa se arriva dal sistema operativo o dall'applicazione.

## DBT

traduco le sensitive instructions into privileged instructions. lo faccio a runtime.

## Hardware assisted Virtualization

new memory structure to define which instructions have to trap.

it's normal trap and emulation but it's supported by hardware.

doppio controllo: posso eseguire in questo ring ? posso eseguire in non root mode ?

se la risposta è si capisco che non devo uscire dalla vm perché è un operazione che il guest os può eseguire autonomamente.

## Memory Virtualization

la shadow table rimane aggiornata grazie ai page faults.
un page fault genera un trap che mi permette di tenere aggiornati i mappings.

nested lookaside buffer. double walk but in hardware.

flush della tlb ogni VMEXIT e VMENTRY.

TLB con tag per evitare i flush.

TLB shadow table in hardware.