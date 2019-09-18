n = int(input())
todos = []
dic = {}

for i in range(n):
    line = input().split(" ")
    todos.append(line[0])
    dic[line[0]] = line[1]

safes = []
unsafes = []

for letra in todos:
    contador = 0
    unsafe = False
    for c in dic[letra]:
        if c in dic:
            if c == letra:
                contador = contador + 1
                if contador > 1:
                    unsafe = True
                    unsafes.append(letra)
                    break;
            else:
                unsafe = True
                unsafes.append(letra)
            break
    if not unsafe:
        safes.append(letra)

all_safes = safes
new_safes = safes

while len(unsafes) > 0:
    if len(new_safes) == 0:
        break

    new_safes = []
    new_unsafes = []

    for letra in unsafes:
        safe = True
        pal = ""
        for i in range(len(dic[letra])):
            if dic[letra][i] in all_safes:
                pal = pal + dic[dic[letra][i]]
            elif dic[letra][i] in unsafes:
                pal = pal + dic[letra][i]
                safe = False
            else:
                pal = pal + dic[letra][i]
        if safe:
            new_safes.append(letra)
            all_safes.append(letra)
        else:
            new_unsafes.append(letra)
        dic[letra] = pal
    unsafes = new_unsafes

n = int(input())
palavra = input()
aux = ""

for c in palavra:
    if c in all_safes:
        aux = aux + dic[c]
    elif c in dic:
        print(-1)
        exit()
    else:
        aux = aux + c
print(aux)