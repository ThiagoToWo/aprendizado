function Lista() { 
	this.cabeca; // ponteiro undefined para o início da lista
	this.topo = 0;
}

Lista.prototype =  {
	obter: function(posicao) {
		var elemento = this.cabeca;

		for (var i = 0; i < posicao; i++) {
			elemento = elemento.proximo;
		}

		return elemento;
	},

	inserir: function(/*{nome, preco, proximo: null}*/novo, posicao) {
		if (posicao >= 0 && posicao <= this.topo) {
			if (posicao == 0) {
				novo.proximo = this.cabeca;
				this.cabeca = novo;
			} else {
				var antecessor = this.obter(posicao - 1);
				var sucessor = antecessor.proximo;

				antecessor.proximo = novo;
				novo.proximo = sucessor;
			}

			this.topo++;

			return true;
		}

		return false;
	},

	remover: function(posicao) {
		if (posicao == 0) {
			this.cabeca = this.cabeca.proximo;
		} else {
			var antecessor = this.obter(posicao - 1);
			var corrente = antecessor.proximo;
			var sucessor = corrente.proximo;

			antecessor.proximo = sucessor;
		}

		this.topo--;
	},

	inserirEmOrdem: function(novo) {
		var corrente = this.cabeca;

		if (this.topo == 0) {
			this.inserir(novo, 0);
			return;
		}

		var i = 0;
		for (; i < this.topo; i++) {
			if (novo.nome < corrente.nome) {
				break;
			}

			corrente = corrente.proximo;
		}

		this.inserir(novo, i);
	},

	imprimir: function() {
		if (this.topo > 0) {
			var i = 1;
			var corrente = this.cabeca;

			console.log("-------itens-------");

			do {
				console.log(i + ". " + corrente.nome + ": " + corrente.preco);
				corrente = corrente.proximo;
				i++;
			} while (corrente != null);
		}
	},

	salvar: function() {
		var dados = {tamanho: this.topo, produtos: this.cabeca}
		localStorage.setItem("dadosDoCrudAprendizado", JSON.stringify(dados));
	},

	carregar: function() {
		var dados = JSON.parse(localStorage.getItem("dadosDoCrudAprendizado"));	
		this.topo = dados.tamanho;	
		this.cabeca = dados.produtos;
	}
}