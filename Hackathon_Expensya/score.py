from solution import *
from random import shuffle
import numpy as np


import sys
def _score(root, tree, employees):
	toprocess = []
	processed_invoice =[]
	for i in range(len(employees)):
		toprocess.append([])
		processed_invoice.append([])

	nvalidated = 0
	
	for i in range(len(tree)):
		if i != root:
			if tree[i] == -1:
				continue
			for invoice in employees[i].invoices:
				all_good = True
				for rule in employees[tree[i]].rules:
					all_good = all_good and rule(invoice)
				if all_good :
					toprocess[tree[i]].append((invoice, i))
		else:
			nvalidated += len(employees[i].invoices)
			processed_invoice[i] = employees[i].invoices


	for i in range(len(tree)):
		toprocess[i].sort()

	for i in range(len(tree)):
		nprocessed = 0
		tprocessed = 0
		for invoice, sub_empl in toprocess[i]:
			if nprocessed + 1 > employees[i].number_process : 
				break
			if tprocessed + invoice.time_process > employees[i].time_process:
				continue
			processed_invoice[sub_empl].append(invoice)
			nprocessed += 1
			nvalidated += 1
			tprocessed += invoice.time_process

	return nvalidated, processed_invoice


employees = read_input("input/TestHackathon-"+sys.argv[1]+".txt")
def calculate_nn_constraint_val(parent, child):
	inv_cnt = 0
	inv_sum = 0
	for invoice in employees[child].invoices:
		all_good = True
		for rule in employees[parent].rules:
			all_good = all_good and rule(invoice)
		if all_good:
			inv_cnt += 1
			inv_sum += invoice.time_process
	return inv_cnt, inv_sum

def greedy_construction(root, employees):
	tree = len(employees) * [-1]
	processed = len(employees) * [False]
	queue = [root]
	processed[root] = True
	while len(queue):
		curr = queue.pop(0)
		curr_n = 0
		curr_t = 0
		for i in range(len(tree)):
			if not processed[i]:
				tree[i] = curr
				processed[i] = True
				queue.append(i)
				inv_cnt, inv_sum = calculate_nn_constraint_val(curr, i)
				curr_n += employees[i].cnt_invoices
				curr_t += employees[i].sum_invoices
			if curr_n > employees[curr].number_process or curr_t > employees[i].time_process:
				break
	for i in range(len(employees)):
		if not processed[i]:
			tree[i] = root
	return tree

def greed_construction_v2(root, employees):
	tree = len(employees) * [-1]
	processed = len(employees) * [False]
	queue = [root]
	processed[root] = True
	invoices = []
	for i in range(len(employees)):
		for inv in employees[i].invoices:
			invoices.append((inv, i))
	invoices.sort(key = lambda x : x[0])
	while len(queue):
		curr_n = 0
		curr_t = 0
		curr = queue.pop(0)
		print(curr)
		# processed[curr] = True
		for inv in invoices:
			if processed[inv[1]]:
				continue
			if (tree[inv[1]] == -1 or tree[inv[1]] == curr) and 1 + curr_n <= employees[curr].number_process and inv[0].time_process + curr_t <= employees[curr].time_process:
				curr_n += 1
				curr_t += inv[0].time_process
				if(tree[inv[1]] == -1):
					queue.append(inv[1])
				tree[inv[1]] = curr
	for i in range(len(employees)):
		if not processed[i]:
			tree[i] = root
	return tree

def greedy_best_first(root, employees):
	tree = len(employees) * [-1]
	processed = len(employees) * [False]
	queue = [root]
	processed[root] = True
	while len(queue):
		curr = queue.pop(0)
		curr_n = 0
		curr_t = 0
		while curr_n <= employees[curr].number_process and curr_t <= employees[curr].time_process:
			best2add = -1
			best_score_add = 0
			for i in range(len(tree)):
				if not processed[i]:
					tree[i] = curr
					new_score, _ = _score(root, tree, employees)
					if new_score > best_score_add:
						best2add = i
					tree[i] = -1

			if best_score_add == 0:
				break
			processed[best2add] = True
			queue.append(best2add)
			tree[best2add] = curr
			inv_cnt, inv_sum = calculate_nn_constraint_val(curr, i)
			curr_n += inv_cnt
			curr_t += inv_sum

	for i in range(len(employees)):
		if not processed[i]:
			tree[i] = root
	return tree

def solve(employees):
	best_score = 0
	best_processed_invoice = None
	best_tree = None
	
	for root in range(len(employees)):
		# perm = np.random.permutation(len(employees))
		tree = greedy_construction(root, employees)
		score, processed_invoice = _score(root, tree, employees)
		if score > best_score:
			best_processed_invoice = processed_invoice
			best_tree = tree
			best_score  = score
	return best_score, best_tree, best_processed_invoice



"""
best_score = 0
best_processed_invoice = None
best_tree = None
with open("resultlol.txt") as f:
	for cnt, line in enumerate(f):
		tree = list(map(int, line.split(" ")[:-1]))
		score, processed_invoice = _score(tree, employees)
		if score > best_score:
			best_processed_invoice = processed_invoice
			best_tree = tree
			best_score  = score
"""


best_score, best_tree, best_processed_invoice = solve(employees) 
print_output(best_tree, employees, best_processed_invoice)
print(best_tree)
print(best_score)


#print("Testing ..")
#f = process_rule("Value Include 1 50")
#print(employees[0].invoices[1].value)
#print(f(employees[0].invoices[1]))











