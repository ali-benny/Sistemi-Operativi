shared boolean needp = false; 
shared boolean needq = false; 
shared int turn;

process P { while (true) {
	/* entry protocol */ 
	needp = true; 
	turn = Q; 
	while (needq && turn != P) ; /* do nothing */ 
	// critical section 
	needp = false;
	non-critical section 
}
process Q { 
	while (true) {
	/* entry protocol */ 
	needq = true; 
	turn = P; 
	while (needp && turn != Q) ; /* do nothing */ 
	// critical section 
	needq = false;
	// non-critical section
	}
}

// Generalizzazione per n processi:
shared int[] stage = new int[N]; /* 0-initialized */ 
shared int[] last = new int[N]; /* 0-initialized */ 

process Pi { 
	while (true) {
	/* Entry protocol */ 
	for (int j=0; j < N; j++) { 
		stage[i] = j; 
		last[j] = i; 
		for (int k=0; k < N; k++) { 
			if (i != k)
				while (stage[k] >= stage[i] && last[j] == i) ;
		} 
	}
	// critical section 
	stage[i] = 0;
	// non-critical section 
	}
}