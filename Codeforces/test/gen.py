from random import randint

T = 1000
print(T)
for i in range(T):
    N = 5
    print(N)
    print(randint(1, N + 1))
    print(randint(500, 10000))
    s = ' '.join([str(randint(0,20)) for i in range(N)])
    print(s)