#include <stdio.h> // printf(), gets()
#include <string.h> // strlen()

void main() {
    char texto[] = "Mas devo explicar-lhe como nasceu toda essa ideia "
            "equivocada de denunciar um prazer e louvar a dor, "
            "e lhe darei um relato completo do sistema, expondo "
            "os ensinamentos reais do grande explorador da verdade, "
            "o mestre-construtor. da felicidade humana. Ninguem "
            "rejeita, nao gosta, ou evita o prazer em si, porque e "
            "prazer, mas porque aqueles que nao sabem como buscar "
            "prazer encontram racionalmente consequencias que sao "
            "extremamente dolorosas. Tampouco ha alguem que ame, "
            "busque ou deseje obter dor de si mesmo, porque e dor, "
            "mas ocasionalmente ocorrem circunstancias em que a labuta "
            "e a dor podem lhe proporcionar um grande prazer. Para "
            "dar um exemplo trivial, qual de nos empreende algum "
            "exercicio fisico laborioso, exceto para obter alguma "
            "vantagem disso? Mas quem tem o direito de criticar um "
            "homem que escolhe desfrutar de um prazer que nao tem "
            "consequencias irritantes, ou alguem que evita uma dor "
            "que nao produz prazer resultante? "
            "Por outro lado, denunciamos com justa indignacao e "
            "antipatia homens que sao tao enganados e desmoralizados "
            "pelos encantos do prazer do momento, tao cegados pelo "
            "desejo, que nao podem prever a dor e os problemas que "
            "estao fadados a acontecer e a culpa igual pertence "
            "aqueles que falham em seu dever atraves da fraqueza da "
            "vontade, o que e o mesmo que dizer atraves do encolhimento "
            "da labuta e da dor. Esses casos sao perfeitamente "
            "simples e faceis de distinguir. Em uma hora livre, "
            "quando nosso poder de escolha e desimpedido e quando "
            "nada impede que sejamos capazes de fazer o que mais "
            "gostamos, todo prazer e para ser bem-vindo e toda dor "
            "evitada. Mas, em certas circunstancias, e devido as "
            "reivindicacoes de dever ou as obrigacoes dos negocios, "
            "frequentemente ocorrera que os prazeres devem ser "
            "repudiados e os aborrecimentos aceitos. O homem "
            "sabio, portanto, sempre se atem a esse principio de "
            "selecao: rejeita os prazeres para assegurar outros "
            "prazeres maiores ou tolera dores para evitar dores piores.";
    char subtexto[100]; // ate 99 caracteres
    int posicao = 0;

    printf("%s\n", texto);
    printf("Insira o subtexto a ser localizado: ");
    gets(subtexto);

    int t = strlen(texto);
    int s = strlen(subtexto);

    for (; posicao < t; posicao++) {
        if (texto[posicao] == subtexto[0]) {
            int achou = 1; // escopo interno ao if acima

            for (int i = 1; i < s; i++) {
                if (texto[posicao + i] != subtexto[i]) {
                    achou = 0;
                    break;
                }
            }

            if (achou) {
                break;
            }
        }
    }

    if (posicao == t) {
        printf("subtexto nao encontrado");
    } else {
        printf("\nA primeira ocorrencia do subtexto \"%s\" se encontra na posicao %d\n", subtexto, posicao);

        for (int i = 0; i < s; i++) {
            texto[posicao + i] += 'A' - 'a';
        }

        printf(texto);
    }
}