function buscar(x, vetor, n) {
	var min = 0;
	var max = n - 1;
	var med;
	
	while (min <= max) {
		med = Math.floor((max + min) / 2);
		
		if (x == vetor[med]) {
			return med;
		}
		
		if (x > vetor[med]) {
			min = med + 1;
		} else {
			max = med - 1;
		}
	}
	
	return -1;
}