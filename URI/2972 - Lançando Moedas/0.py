n = int(input())
n = '{:b}'.format(n)
print(1 << n.count('1'))