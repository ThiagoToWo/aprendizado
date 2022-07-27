function tokenizar(texto, separadores) {
    var tokens = new Array(128);
    var palavra = "";
    var achou = false;
    var posicao = 0;

    for (var i = 0; i < texto.length; i++) {
        for (var j = 0; j < separadores.length; j++) {
            if (texto[i] == separadores[j]) {
                achou = true;
                break;
            }           
        }

        if (!achou) {
            palavra += texto[i];
        } else {
            tokens[posicao] = palavra;
            posicao++;
            palavra = "";
            achou = false;
        }
    }

    tokens[posicao] = palavra;

    return tokens;
}