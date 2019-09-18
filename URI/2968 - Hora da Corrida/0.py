from math import ceil
n, v = [int(v) for v in input().split()]

resp = []
for i in range(10, 100, 10):
    resp.append(str(ceil(n * v * i / 100)))

print(' '.join(resp))