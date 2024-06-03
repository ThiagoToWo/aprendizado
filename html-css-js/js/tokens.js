function tokenizar(texto, separadores) {
    const tokens = new Array(128);
    let palavra = "";
    let achou = false;
    let posicao = 0;

    for (let i = 0; i < texto.length; i++) {
        for (let j = 0; j < separadores.length; j++) {
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