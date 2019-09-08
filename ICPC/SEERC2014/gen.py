from random import randint

N = 6000
K = 6000
M = 1000000000
for i in range(10):
    print(str(N) + ' ' + str(K))
    S = ' '.join([str(randint(0, M)) for i in range(N)])
    print(S)
    for i in range(K):
        L = randint(1, N)
        R = randint(1, N)
        print(str(min(L, R)) + ' ' + str(max(L, R)))
    print(str(N) + ' ' + str(K))
    S = ' '.join([str(randint(0, M)) for i in range(N)])
    print(S)
    for i in range(K):
        L = randint(1, N)
        R = randint(1, N)
        print(str(min(L, R)) + ' ' + str(max(L, R)))
print("0 0\n");
    