from random import randint

for i in range(100):
    s = ' '.join([str(randint(1, 6)) for i in range(2)])
    print(s)

