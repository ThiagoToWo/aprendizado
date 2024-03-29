const fila = function() {
	var max = 100;
	var fila = new Array(max);
	var inicio = 0;
	var fim = 0;
	
	function inserir(valor) {
		if (fim == max) {
			max *= 2;
			var temp = new Array(max);
			
			for (var i = inicio; i < max / 2; i++) {
				temp[i - inicio] = fila[i];
			}
			
			fila = temp;
			inicio = 0
			fila[fim] = valor;
		} else {
			fila[fim] = valor;
		}
		
		fim++;
	}
	
	function remover() {
		if (fim == inicio) {
			document.write("Fila vazia<br>");
		} else {
			var elemento = fila[inicio];
			inicio++;
			return elemento;
		}
	}
	
	function imprimir() {
		for (var i = inicio; i < fim; i++) {
			document.write(fila[i] + " ");
		}
	}
	
	function tamanho() {
		return fim - inicio;
	}
	
	return {
		inserir: inserir,
		remover: remover,
		imprimir: imprimir,
		tamanho: tamanho
	}
}();