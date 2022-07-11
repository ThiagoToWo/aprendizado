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

	function inserir(nome, preco, posicao) {
		if (posicao >= 0 && posicao <= topo) {
			var novo = { nome, preco, proximo: null };

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

	function inserirEmOrdem(nome, preco) {
		var corrente = cabeca;

		if (topo == 0) {
			inserir(nome, preco, 0);
			return;
		}

		var i = 0;

		for (; i < topo; i++) {
			if (nome < corrente.nome) {
				break;
			}

			corrente = corrente.proximo;
		}

		inserir(nome, preco, i);
	}

	function imprimir() {
		if (topo >= 0) {
			var i = 1;
			var corrente = cabeca;

			console.log("-------itens-------");

			do {
				console.log(i + ". " + corrente.nome + ": " + corrente.preco);
				corrente = corrente.proximo;
				i++;
			} while (corrente != null);
		}
	}

	return {
		remover: remover,
		obter: obter,
		imprimir: imprimir,
		inserirEmOrdem: inserirEmOrdem
	}
}()); 