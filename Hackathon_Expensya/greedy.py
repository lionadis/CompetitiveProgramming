import numpy as np
import sys


from solution import *
from score import _score


employees = read_input("input/TestHackathon-"+sys.argv[1]+".txt")

class UnionFind:
    def __init__(self, n):
        self._id = list(range(n))
        self._sz = [1] * n

    def find(self, u):
        if(self._id[u] == u):
            return u
        self._id[u] = self.find(self._id[u])
        return self._id[u]

    def same_set(self, u, v):
        return self.find(u) == self.find(v)

    def union(self, u, v):
        u, v = self.find(u), self.find(v)
        if u == v:
            return False
        if self._sz[u] < self._sz[v]:
            u, v = v, u
        self._id[v] = u
        self._sz[v] += self._sz[u]
        return True

uf = UnionFind(len(employees))

par = [-1] * len(employees)

root_fixed = False

emp_sorted = np.argsort(employees)

childs = [[]] * len(emp_sorted)
for e1 in emp_sorted:
    best_par, best_score = -1, -1
    for e2 in emp_sorted:
        if e1 == e2:
            continue
        curr_score = _score([1] * len(childs[e2]) + [1, -1], childs[e2] + [employees[e1], employees[e2]])[0]
        if best_score < curr_score and not uf.same_set(e1, e2):
            best_score, best_par = curr_score, e2
    if best_par == -1:
        if not root_fixed:
            root_fixed = True
        else:
            for e2 in emp_sorted:
                if e1 == e2:
                    continue
                if not uf.same_set(e1, e2):
                    p[e1] = e2
                    uf.union(e1, e2)
                    break
    else :
        childs[e2].append(employees[e1])
        uf.union(e1, best_par)
        par[e1] = best_par

def submit(parents):
    scr, invoices = _score(parents, employees)
    print_output(parents, employees, invoices)
    print(scr)
submit(par)

        