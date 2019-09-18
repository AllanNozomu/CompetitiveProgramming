n, m = map(int, input().split())
p1, p2 = map(int, input().split())
r1, r2 = map(int, input().split())

n = n // 2 + 1
m = m // 2 + 1

p1 = p1 // 2 + 1
p2 = p2 // 2 + 1

r1 = r1 // 2 + 1
r2 = r2 // 2 + 1

total = n * m

p = (p1 + p2) % 2
r = (r1 + r2) % 2

if total % 2 == 0:
    if p != r:
        print(n * m * 2 - 1)
    else:
        print(n * m * 2 - 3)
else:
    if p == r:
        if p == 0:
            print(n * m * 2 - 1)
        else:
            print(n * m * 2 - 5)
    else:
        print(n * m * 2 - 3)