import random as rnd # random.randrange()

random = rnd.randrange(1, 101)
tentativas = 1
palpite = int(input("Dê seu palpite (sair = -1): "))

# não tem do ... while em Python
while palpite != -1:
    if palpite > random:
        print("Tente um menor")
    else: 
        if palpite < random:
            print("Tente um maior")
        else:
            print("Acertou.\nForam", tentativas, "tentativas")
            break
    tentativas += 1
    palpite = int(input("Dê seu palpite (sair = -1): "))