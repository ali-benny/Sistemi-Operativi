> le azioni atomiche vengono in modo indivisiile
> Soddisfano la condizione *o tutto o niente*

## Parallelismo reale
Garantisce che l'azione non interferisca con altri processi durante la sua esecuzione

## Parallelismo apparente
L'avvicendamento [[Context switch]] fra i processi avviene prima o dopo l'azione, che quindi non può intervenire.

#### Esempio
`sw $a0, ($t0)`

#### Contro Esempio


![[Pasted image 20211021153736.png]]

Assumiamo che in ogni istante, vi possa essere al massimo un accesso alla memoria alla volta.
Questo significa che XX

### Una notazione per le operazioni atomiche
<S> per indicare che lo statement S deve essere eseguito in modo atomico. 
	
#### Esempio
	
	
![[Pasted image 20211021154109.png]]
L'output del programma nella slide 46 in foto è una distribuzione di probabilità che prevede un output per ogni percorso.
	
