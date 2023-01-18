shared int turn = P; 
shared boolean needp = false; 
shared boolean needq = false;

process P {
	while (true) {
		/* entry protocol */ 
		needp = true; 
		while (needq) 
			if (turn == Q) { 
				needp = false; 
				while (turn == Q) ; 
				/* do nothing */ 
				needp = true;
			}
		/* critical section */
		needp = false; 
		turn = Q; 
		/* non-critical section */
	}
}
process Q {
	while (true) {
	/* entry protocol */ 
		needq = true; 
		while (needp) 
			if (turn == P) { 
				needq = false; 
				while (turn == P) ; 
				/* do nothing */ 
				needq = true;
			}
		/* critical section */
		needq = false; 
		turn = P;
		/* non-critical section */
	}
}