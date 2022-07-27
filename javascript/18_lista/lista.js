const lista = (function() {
	var cabeca = {};
	var topo = 0;
	
	function empilhar(valor) {
		var novo = {dado: valor, proximo: null};
		
		if (topo == 0) {
			cabeca = novo;
		} else {
			var corrente = cabeca;
			
			while (corrente.proximo != null) {
				corrente = corrente.proximo;
			}
			
			corrente.proximo = novo;
		}
		
		topo++;
	}
	
	function inserir(valor, posicao) {
		if (posicao >=0 && posicao <= topo) {
			var novo = {dado: valor, proximo: null};
			
			if (posicao == 0) {
				novo.proximo = cabeca;
				cabeca = novo;
			} else {
				var antecessor = obter(posicao - 1);
				var sucessor = antecessor.proximo;
				
				antecessor.proximo = novo;
				novo.proximo = sucessor;				
			}
			
			topo++;
			
			return true;
		}
		
		return false;
	}
	
	function remover(posicao) {
		if (posicao == 0) {
			cabeca = cabeca.proximo;
		} else {
			var antecessor = obter(posicao - 1);
			var corrente = antecessor.proximo;
			var sucessor = corrente.proximo;
			
			antecessor.proximo = sucessor;
		}
		
		topo--;
	}
	
	function obter(posicao) {
		var elemento = cabeca;
		
		for (var i = 0; i < posicao; i++) {
			elemento = elemento.proximo;
		}
		
		return elemento;
	}
	
	function imprimir() {
		if (topo > 0) {
			var corrente = cabeca;
			
			document.write(corrente.dado + " ");
			
			while (corrente.proximo != null) {
				corrente = corrente.proximo;
				document.write(corrente.dado + " ");
			}
		}
	}
	
	function tamanho() {
		return topo;
	}
	
	function inserirEmOrdem(valor) {
		var corrente = cabeca;
		
		if (topo == 0) {
			inserir(valor, 0);
			return;
		}
		
		var i = 0;
		
		for (; i < topo; i++) {
			if (valor < corrente.dado) {
				break;
			}
			
			corrente = corrente.proximo;
		}
		
		inserir(valor, i);
	}
	
	return {
		empilhar: empilhar,
		inserir: inserir,
		remover: remover,
		obter: obter,
		imprimir: imprimir,
		tamanho: tamanho,
		inserirEmOrdem: inserirEmOrdem
	}
}()); 