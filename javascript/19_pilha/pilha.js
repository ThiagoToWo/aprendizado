const pilha = (function() {
	var max = 100;
	var pilha = new Array(max);
	var topo = -1;
	
	function empilhar(valor) {
		topo++
		
		if (topo == max) {
			max *= 2;
			var temp = new Array(max);
			
			for (var i = 0; i < max / 2; i++) {
				temp[i] = pilha[i];
			}
			
			pilha = temp;
			
			pilha[topo] = valor;
		} else {
			pilha[topo] = valor;
		}
	}
	
	function desempilhar() {
		if (topo == -1) {
			document.write("Pilha vazia<br>")
		} else {
			var elemento = pilha[topo];
			topo--;
			return elemento;
		}
	}
	
	function imprimir() {
		for (var i = 0; i <= topo; i++) {
			document.write(pilha[i] + " ");
		}
	}
	
	function tamanho() {
		return topo + 1;
	}
	
	return {
		empilhar: empilhar,
		desempilhar: desempilhar,
		imprimir: imprimir,
		tamanho: tamanho
	}
}());