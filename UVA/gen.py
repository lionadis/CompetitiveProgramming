from random import randint
T = 20
print(T)
for _ in range(T):
    print("%d %d"%(randint(2, 6), randint(1, 1000000000)))