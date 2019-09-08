import itertools
import random 
all_perms = list(itertools.permutations(['A','B','C','D','E']))
random.shuffle(all_perms)
chosen = all_perms[-1]
all_perms.pop()
max_iter = 10
merged = list(itertools.chain(*all_perms))
print(''.join(merged))
print(chosen)
for i in range(max_iter):
	idx = random.randint(0, 594)
	print(merged[idx])
	
