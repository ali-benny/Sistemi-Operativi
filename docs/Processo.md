Processo = è un'attività controllata da un programma che si svolge su un processore (entità dinamica)

Processo != programma

># Assioma di[[finite progress]]
>XXX

## Stato di un processo 
può essere totalmente descritto dalle seguenti componenti
1.
2.
3.

Più processi possono eseguire lo stesso programma. 
Il codice è l'unica cosa che si può condividere, poichè i processi dipendono dall'esecuzione del programma. 

# Gli stati del processo
- **Running**: il processo è in esecuzione
- **Waiting**: il processo è in attesa di qualche evento esterno
	- es: completamento di un operazione I/O non può essere eseguito
-**Ready**: il processo può essere eseguito, ma attualmente il processore è impegnato in altre attività.
[[finite progress]]
# Concorrenza
Riguarda la gestione di processi multipli:
- **Multiprogramming**
- **Multiprocessing**
- **MultiXX**

>### Def.
>è l'insieme di notaizoni per descrivere l'esecuzione concorrente di due o più programmi.
>è l'insieme di tecniche per riscrivere i problemi associati all'esecuzione concorrente.

## Dove troviamo la concorrenza?
### Applicazioni multiple
### Applicazione strutturate su processi
### Struttura del sistema operativo


# Multiprocessing vs multiprogramming
Multiprocessing sono eseguiti da processori diversi rispetto a quando sono eseguiti dallo stesso processore

in un singolo processore:
- Multiprocessi sono alternati nel tempo

![[Pasted image 20211021144442.png]]

## [[Race Condition]]

# Interazione tra processi
E' possibile classificare le modalità di interazione tra processi in base a quanto sono "consapevoli" uno dell'altro. 
Processi totalmente "ignari" uno dell'altro: 
- processi indipendenti non progettati per lavorare insieme  sebbene siano indipendenti, vivono in un ambiente comune 
Come interagiscono?
	competono per le stesse risorse, devono sincronizzarsi nella loro utilizzazione  Il sistema operativo:  deve arbitrare questa competizione, fornendo meccanismi di sincronizzazione

[[Proprietà Safety]]