from random import randint, sample

T = 10
for i in range(T):
    N = randint(1,50000)
    print(N)
    A = sample(range(1,50002), N)
    S = ' '.join([str(x) for x in A])
    print(S)
        