from random import choice

lowercases = "ab"
N = 5000
print(''.join([choice(lowercases) for i in range(N)]))

