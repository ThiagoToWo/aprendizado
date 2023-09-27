texto = """Mas devo explicar-lhe como nasceu toda essa idéia
        equivocada de denunciar um prazer e louvar a dor,
        e lhe darei um relato completo do sistema, expondo
        os ensinamentos reais do grande explorador da verdade,
        o mestre-construtor. da felicidade humana. Ninguém
        rejeita, não gosta, ou evita o prazer em si, porque é
        prazer, mas porque aqueles que não sabem como buscar
        prazer encontram racionalmente consequências que são
        extremamente dolorosas. Tampouco há alguém que ame,
        busque ou deseje obter dor de si mesmo, porque é dor,
        mas ocasionalmente ocorrem circunstâncias em que a labuta
        e a dor podem lhe proporcionar um grande prazer. Para
        dar um exemplo trivial, qual de nós empreende algum
        exercício físico laborioso, exceto para obter alguma
        vantagem disso? Mas quem tem o direito de criticar um
        homem que escolhe desfrutar de um prazer que não tem
        consequências irritantes, ou alguém que evita uma dor
        que não produz prazer resultante?
        Por outro lado, denunciamos com justa indignação e
        antipatia homens que são tão enganados e desmoralizados
        pelos encantos do prazer do momento, tão cegados pelo
        desejo, que não podem prever a dor e os problemas que
        estão fadados a acontecer e a culpa igual pertence
        àqueles que falham em seu dever através da fraqueza da
        vontade, o que é o mesmo que dizer através do encolhimento
        da labuta e da dor. Esses casos são perfeitamente 
        simples e fáceis de distinguir. Em uma hora livre,
        quando nosso poder de escolha é desimpedido e quando
        nada impede que sejamos capazes de fazer o que mais
        gostamos, todo prazer é para ser bem-vindo e toda dor
        evitada. Mas, em certas circunstâncias, e devido às
        reivindicações de dever ou às obrigações dos negócios,
        frequentemente ocorrerá que os prazeres devem ser
        repudiados e os aborrecimentos aceitos. O homem 
        sábio, portanto, sempre se atém a esse princípio de 
        seleção: rejeita os prazeres para assegurar outros
        prazeres maiores ou tolera dores para evitar dores piores."""

posicao = 0 # variável global

print(texto)
subtexto = input("Insira o subtexto a ser localizado: ")

t = len(texto)
s = len(subtexto)

while posicao < t: # tem que ser while, por a variável em for é local
    if texto[posicao] == subtexto[0]:
        achou = True # escopo interno ao if acima

        for i in range(1, s):
            if texto[posicao + i] != subtexto[i]:
                achou = False
                break

        if achou:
            break
    
    posicao += 1

if posicao == t:
    print("Subtexto não encontrado")
else:
    print("\nA primeira ocorrência do subtexto \"" + str(subtexto) + 
          "\" se inicia na posição " + str(posicao))
    
    print(texto[: posicao] + 
          texto[posicao : posicao + s].upper() +
          texto[posicao + s :])