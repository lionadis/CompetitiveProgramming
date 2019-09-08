import json
from bisect import *
n = int(input())
names = {}
for i in range(0,n):
	s = json.loads(input())
	for author in s['authors']['authors']:
		if names.get(author['full_name']):
			names[author['full_name']].extend([s['citing_paper_count']])
		else:
			names[author['full_name']] = [s['citing_paper_count']]
ans = []
for name, value in names.items():
	value.sort()
	l, r = 0, 10000
	while l < r:
		mid = (l + r + 1) // 2
		cnt = bisect_left(value, mid)
		if mid <= len(value) - cnt:
			l = mid
		else:
			r = mid - 1
	ans.append((name, l))
ans = sorted(ans, key=lambda x:x[0])
ans = sorted(ans, key=lambda x:x[1], reverse=True)
for (name, score) in ans:
	print(name, score)

