//produto = {nome: "", preco: 0, proximo: {}}

function inserirEmOrdem(inicio, novo) {
	if (inicio.nome == undefined) { // em JS só se atribui por referência as propriedades dos objetos
        inicio.nome = novo.nome;
        inicio.preco = novo.preco;
        inicio.proximo = null;
        return;
    }
    
    var antecessor;
	var corrente = inicio;

    while (corrente != null) {
        if (novo.nome < corrente.nome) {
            return;
        }

        antecessor = corrente;
        corrente = corrente.proximo;
    }
	
	antecessor.proximo = novo;
	novo.proximo = corrente;
}

function obter(inicio, posicao) {
    var elemento = inicio;

    for (var i= 0; i < posicao; i++) {
        elemento = elemento.proximo;
    }

    return elemento;
}
	

function remover(inicio, posicao) {
    if (posicao == 0) { // em JS só se atribui por referência as propriedades dos objetos
        var segundo = inicio.proximo;
       
        inicio.nome = segundo.nome;
        inicio.preco = segundo.preco;
        inicio.proximo = segundo.proximo;
    } else {
        var antecessor = obter(inicio, posicao - 1);
        var corrente = antecessor.proximo;
        var sucessor = corrente.proximo;
    
        antecessor.proximo = sucessor;
    }    
}

function imprimir(inicio) {
    if (inicio != null) {
        var indice = 1;
        var corrente = inicio;

        console.log(indice + "." + corrente.nome + ", R$ " + corrente.preco + "\n");

        while (corrente.proximo != null) {
            indice++;
            corrente = corrente.proximo;
            console.log(indice + "." + corrente.nome + ", R$ " + corrente.preco + "\n");
        }
    }
}
	