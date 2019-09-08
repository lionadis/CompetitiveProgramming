from random import choice

T = 1000
print(T)
for i in range(T):
    N = 10
    print(N)
    s = "".join(choice(['.', '+']) for i in range(N))
    print(s)