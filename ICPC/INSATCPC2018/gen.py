from random import randint

N = 100000
Q = 100000
MAXN = 100000
print(N, Q)
a = ' '.join([str(randint(1,MAXN)) for i in range(N)])
print(a)
for i in range(Q):
	q = []
	q.append(str(randint(1, 2)))
	l = randint(1, N)
	d = randint(0, N - l)
	q.append(str(l))
	q.append(str(l + d))
	print(' '.join(q))

