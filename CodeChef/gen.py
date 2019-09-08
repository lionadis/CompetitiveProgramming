from random import randint
T, N, Q = 100, 10, 1
print(T)
for t in range(T):
    print(N)
    print(Q)
    a = [str(randint(1,1000000000)) for i in range(N)]
    print(' '.join(a))
    for i in range(Q):
        print(a[randint(1,N) - 1])