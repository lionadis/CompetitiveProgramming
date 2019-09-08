#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <limits>
#include <cstring>

using namespace std;

int a[100010];
int b[100010];
vector<int> primes;
vector<int> minPr;

void init(int limit)
{
	minPr.resize(limit + 1, 0);
	for (int i = 2; i <= limit; i++)
	{
		if (minPr[i] == 0)
		{
			primes.push_back(i);
			minPr[i] = i;
		}
		for (auto pr : primes)
		{
			long long num = i * 1LL * pr;
			if (num > limit)
				break;
			if (pr > minPr[i])
				break;
			minPr[num] = pr;
		}
	}
}

int minNum = 2;
set<int> prs;

vector<int> getPrimes(int n)
{
	int cur = n;
	vector<int> res;
	while (cur > 1)
	{
		int p = minPr[cur];
		while (cur % p == 0)
			cur /= p;
		res.push_back(p);
	}
	return res;
}

bool check(int num)
{
	if (num == 1)
		return false;
	vector<int> ps = getPrimes(num);
	for (int prime : ps)
	{
		if (prs.find(prime) != prs.end())
			return false;
	}
	for (int prime : ps)
		prs.insert(prime);
	return true;
}

int main()
{
	int n;
	init(1000 * 1000 * 10);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	bool wasUp = false;
	for (int i = 0; i < n; i++)
	{
		while (!check(a[i]))
		{
			a[i]++;
			wasUp = true;
		}
		if (wasUp)
		{
			int ind = 0;
			auto it = prs.begin();
			while (it != prs.end())
			{
				if (*it == primes[ind])
				{
					primes[ind] = 0;
					it++;
				}
				ind++;
			}
			ind = 0;
			for (int j = i + 1; j < n; j++)
			{
				while (primes[ind] == 0)
					ind++;
				a[j] = primes[ind];
				ind++;
			}
			break;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;