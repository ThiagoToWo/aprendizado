function media(vetor, n) {
	var soma = 0;
	
	for (var i = 0; i < n; i++) {
		soma += vetor[i];
	}
	
	return soma / n;
}

function mediana(vetor, n) {
	ordenar(vetor, n); // importar ordenar do arquivo ordenação
	
	if (n % 2 != 0) {
		return vetor[(n + 1) / 2 - 1];
	} else {
		return (vetor[n / 2 - 1] + vetor[n / 2]) / 2;
	}
}

function frequencia(vetor, n) {
	var f = [];
	
	for (var i = 0; i < n - 1; i++) {
		for (var j = i + 1; j < n; j++) {
			if (f[i] == null) {
				f[i] = 1;
			}
			
			if (f[j] == null) {
				f[j] = 1;
			}
			
			if (vetor[i] == vetor[j]) {
				f[i]++;
				f[j]++;
			}
		}
	}
	
	return f;
}

function maximo(vetor, n) {
	var max = vetor[0];
	
	for (var i = 1; i < n; i++) {
		if (vetor[i] > max) {
			max = vetor[i];
		}
	}
	
	return max;
}

function minimo(vetor, n) {
	var min = vetor[0];
	
	for (var i = 1; i < n; i++) {
		if (vetor[i] < min) {
			min = vetor[i];
		}
	}
	
	return min;
}

function moda(vetor, n) {
	var freq = frequencia(vetor, n);
	var max = maximo(freq, n);
	var moda;
	
	for (var i = 0; i < n; i++) {
		if (freq[i] == max) {
			moda = vetor[i];
		}
	}
	
	return moda;
}

function variancia(vetor, n) {
	var m = media(vetor, n);
	var d2 = 0;
	
	for (var i = 0; i < n; i++) {
		d2 += (vetor[i] - m) * (vetor[i] - m);
	}
	
	return d2 / n;
}

function aleatorio(semente) {
	const iteracao = semente.valor % 37;

	for (var i = 0; i <= iteracao; i++) {
		semente.valor = (314159265 * semente.valor + 13579) % Number.MAX_SAFE_INTEGER; 
	}

    return semente.valor / Number.MAX_SAFE_INTEGER;
}