shared lock = 0; 

process P {
	int vp;
	while (true) { 
		do {
			TS(lock, vp);
		} while (vp); 
		// critical section 
		lock = 0;
		// non-critical section 
	} 
}
process Q {
	int vp; 
	while (true) { 
		do {
			TS(lock, vp);
		} while (vp); 
		// critical section 
		lock = 0;
		// non-critical section
	}
}