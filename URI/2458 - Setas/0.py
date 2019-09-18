import sys

matriz = []
safes = {}

def dfs(x, y):
    if x < 0 or x >= len(matriz) or y < 0 or y >= len(matriz):
        return False

    if (x,y) in safes:
        return safes[(x,y)]

    safes[(x,y)] = True
    
    if matriz[x][y] == "A":
        safes[(x,y)] = dfs(x-1, y)
    elif matriz[x][y] == "<":
        safes[(x,y)] = dfs(x, y-1)
    elif matriz[x][y] == ">":
        safes[(x,y)] = dfs(x, y+1)
    else:
        safes[(x,y)] = dfs(x+1, y)
    return safes[(x,y)]

N = int(input())
for i in range(N):
    matriz.append(list(input()))

sys.setrecursionlimit(N ** 3)
res = 0
for i in range(len(matriz)):
    for j in range(len(matriz)):
        if (i,j) not in safes:
            dfs(i,j)
        if safes[(i,j)]:
            res += 1
print(res)