> Una proprietà di un programma concorrente è un attributo che rimane vero per ogni possibile storia di esecuzione del programma stesso

## Due tipi di proprietà: 
- Safety ("nothing bad happens"): mostrano che il programma (se avanza) va "nella direzione voluta", cioè non esegue azioni scorrette 
- Liveness ("something good eventually happens"): il programma avanza, non si ferma... insomma è “vitale”

#### Esempio del consenso
Consensus, dalla teoria dei sistemi distribuiti 
	Si consideri un sistema con N processi: 
		All'inizio, ogni processo propone un valore 
		Alla fine, tutti i processi si devono accordare su uno dei valori proposti (decidono quel valore) 
Proprietà di safety 
	Se un processo decide, deve decidere uno dei valori proposti 
	Se due processi decidono, devono decidere lo stesso valore 
Proprietà di liveness 
	Prima o poi ogni processo corretto (i.e. non in crash) prenderà una decisione
### Programmi sequenziali
le [[Proprietà Safety]] esprimono la correttezza dello stato finale (il risultato è quello voluto)

La principale proprietà di [[liveness]] è la terminazione