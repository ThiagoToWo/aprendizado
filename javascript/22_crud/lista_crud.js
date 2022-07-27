const lista = (function () {
	var cabeca = {};
	var topo = 0;

	function obter(posicao) {
		var elemento = cabeca;

		for (var i = 0; i < posicao; i++) {
			elemento = elemento.proximo;
		}

		return elemento;
	}

	function inserir(/*{nome, preco, proximo: null}*/novo, posicao) {
		if (posicao >= 0 && posicao <= topo) {
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

	function inserirEmOrdem(novo) {
		var corrente = cabeca;

		if (topo == 0) {
			inserir(novo, 0);
			return;
		}

		var i = 0;

		for (; i < topo; i++) {
			if (novo.nome < corrente.nome) {
				break;
			}

			corrente = corrente.proximo;
		}

		inserir(novo, i);
	}

	function imprimir() {
		if (topo > 0) {
			var i = 1;
			var corrente = cabeca;

			console.log("-------itens-------");

			do {
				console.log(i + ". " + corrente.nome + ": " + corrente.preco);
				corrente = corrente.proximo;
				i++;
			} while (corrente.proximo != null);
		}
	}

	function salvar() {
		var dados = {tamanho: topo, produtos: cabeca}
		localStorage.setItem("dadosDoCrudAprendizado", JSON.stringify(dados));
	}

	function carregar() {
		var dados = JSON.parse(localStorage.getItem("dadosDoCrudAprendizado"));	
		topo = dados.tamanho;	
		cabeca = dados.produtos;
	}

	return {
		remover: remover,
		obter: obter,
		imprimir: imprimir,
		inserirEmOrdem: inserirEmOrdem,
		salvar: salvar,
		carregar: carregar
	}
}()); 