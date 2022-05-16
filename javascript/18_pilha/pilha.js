const pilha = (function() {
	var tam = 100;
	var pilha = new Array(tam);
	var topo = -1;
	
	function empilhar(valor) {
		topo++
		
		if (topo == tam) {
			tam *= 2;
			var temp = new Array(tam);
			
			for (var i = 0; i < tam; i++) {
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