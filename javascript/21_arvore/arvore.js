const arvore = function() {
	var raiz = null;
	
	function inserir(valor) {
		raiz = inserirNo(raiz, valor);
	}
	
	function remover(valor) {
		raiz = removerNo(raiz, valor);
	}
	
	function pesquisar(valor) {
		return pesquisarNo(raiz, valor);
	}
	
	function preOrdem(callback) {
		pre(raiz, callback);
	}
	
	function emOrdem(callback) {
		em(raiz, callback);
	}
	
	function posOrdem(callback) {
		pos(raiz, callback);
	}
	
	function min() {
		return minNo(raiz);
	}
	
	function max() {
		return maxNo(raiz);
	}
	
	// funções utilitárias recursivas
	function inserirNo(subraiz, valor) {
		if (subraiz == null) {
			return  {dado: valor, esquerdo: null, direito: null};
		} else if (valor < subraiz.dado) {
			subraiz.esquerdo = inserirNo(subraiz.esquerdo, valor);
		} else if (valor > subraiz.dado) {
			subraiz.direito = inserirNo(subraiz.direito, valor);
		}
		
		return subraiz;
	}
	
	function removerNo(subraiz, valor) {
		if (valor < subraiz.dado) {
			subraiz.esquerdo = removerNo(subraiz.esquerdo, valor);
		} else if (valor > subraiz.dado) {
			subraiz.direito = removerNo(subraiz.direito, valor);
		} else {
			if (subraiz.esquerdo == null && subraiz.direito == null) { // folha
				subraiz = null;
			} else if (subraiz.direito == null) { // só esquerdo
				subraiz = subraiz.esquerdo;
			} else if (subraiz.esquerdo == null) { // só direito
				subraiz = subraiz.direito;
			} else { // tem os dois
				var sucessor = minNo(subraiz.direito);
				subraiz.dado = sucessor.dado;
				subraiz.direito = removerNo(subraiz.direito, sucessor.dado);
			}
		}
		
		return subraiz;
	}
	
	function pesquisarNo(subraiz, valor) {
		if (subraiz == null) {
			return false;			
		} else if (valor < subraiz.dado) {
			return pesquisarNo(subraiz.esquerdo, valor);			
		} else if (valor > subraiz.dado) {
			return pesquisarNo(subraiz.direito, valor);
		} else {
			return true;
		}
	}
	
	function pre(subraiz, callback) {
		if (subraiz == null) {
			return;
		}
		
		callback(subraiz.dado);
		pre(subraiz.esquerdo, callback);
		pre(subraiz.direito, callback);
	}
	
	function em(subraiz, callback) {
		if (subraiz == null) {
			return;
		}
		
		em(subraiz.esquerdo, callback);
		callback(subraiz.dado);
		em(subraiz.direito, callback);
	}
	
	function pos(subraiz, callback) {
		if (subraiz == null) {
			return;
		}
		
		pos(subraiz.esquerdo, callback);
		pos(subraiz.direito, callback);
		callback(subraiz.dado);
	}
	
	function minNo(subraiz) {
		if (subraiz.esquerdo == null) {
			return subraiz;
		} else {
			return minNo(subraiz.esquerdo);
		}
	}
	
	function maxNo(subraiz) {
		if (subraiz.direito == null) {
			return subraiz;
		} else {
			return maxNo(subraiz.direito);
		}
	}
	
	return {
		inserir: inserir,
		remover: remover,
		pesquisar: pesquisar,
		preOrdem: preOrdem,
		emOrdem: emOrdem,
		posOrdem: posOrdem,
		min: min,
		max: max
	}
}();