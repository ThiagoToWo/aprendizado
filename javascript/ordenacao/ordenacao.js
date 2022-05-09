function ordenar(vetor, n) {
	for (var i = 1; i < n; i++) {
		for (var j = 0; j < n - i; j++) {
			if (vetor[j] > vetor[j + 1]) {
				var temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
}