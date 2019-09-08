from datetime import datetime
from itertools import permutations, product

class Employee:
	def __init__(self, name, time_process, number_process, invoices, rules):
		self.name = name
		self.time_process = time_process
		self.number_process = number_process
		self.invoices = invoices
		self.cnt_invoices = len(self.invoices)
		self.sum_invoices = sum([invoice.time_process for invoice in self.invoices])
		self.rules = rules

	def __repr__(self):
		return "Name : " + self.name  + "\n" + \
			"Max time to process : " + str(self.time_process) + "\n" + \
			"Max number to process : " + str(self.number_process) +"\n" + \
			"Invoices : "  + str(len(self.invoices)) + "\n" + \
			"Rules : " + str(len(self.rules)) + "\n"



class Invoice:
	def __init__(self, name, value, category, date, project, country, time_process):
		self.name = name
		self.value = value
		self.category = category
		self.date = date
		self.project = project
		self.country = country
		self.time_process = time_process

	def __repr__(self):
		return "Name : " + self.name
	def __lt__(self, other):
		return self.name < other.name

def read_input(fpath):
	employees = []
	with open(fpath, 'r', encoding="utf-8") as f:
		N = int(f.readline()[:-1])
		for i in range(N):
			rules = []
			invoices = []
			name = f.readline()[:-1]
			t_process = float(f.readline()[:-1])
			n_process = int(f.readline()[:-1])
			n_invoices = int(f.readline()[:-1])
			for j in range(n_invoices):
				i_name = f.readline()[:-1]
				i_value = float(f.readline()[:-1])
				i_cat = f.readline()[:-1]
				i_date = datetime.strptime(f.readline()[:-1], "%d/%m/%Y")
				i_project = f.readline()[:-1]
				i_country = f.readline()[:-1]
				i_t_process = float(f.readline()[:-1])
				invoices.append(Invoice(i_name, i_value, i_cat, i_date, i_project, i_country, i_t_process))
			n_rules = int(f.readline()[:-1])
			for j in range(n_rules):
				rules.append(process_rule(f.readline()[:-1]))
			employees.append(Employee(name, t_process, n_process, invoices, rules))
	return employees


def process_rule(rule):
	rr = rule.split(" ")

	if rr[0] == "Category":
		if rr[1] == "Include":
			return lambda x : x.category in set(rr[2:])
		else :
			return lambda x : not(x.category in set(rr[2:]))

	if rr[0] == "Country":
		if rr[1] == "Include":
			return lambda x : x.country in set(rr[2:])
		else :
			return lambda x : not(x.country in set(rr[2:]))
	
	if rr[0] == "Project":
		if rr[1] == "Include":
			return lambda x : x.project in set(rr[2:])
		else :
			return lambda x : not (x.project in set(rr[2:]))

	if rr[0] == "Value":
		if rr[1] == "Include":
			return lambda x : (x.value >= float(rr[2]) and x.value <= float(rr[3]))
		else :
			return lambda x : (x.value < float(rr[2]) or x.value > float(rr[3]))

	if rr[0] == "Date":
		if rr[1] == "Include":
			return lambda x : (x.date >= datetime.strptime(rr[2], "%d/%m/%Y") and x.date <= datetime.strptime(rr[3], "%d/%m/%Y"))
		else :
			return lambda x : (x.date < datetime.strptime(rr[2], "%d/%m/%Y") or x.date > datetime.strptime(rr[3], "%d/%m/%Y"))
	
	

def print_output(tree, employees, processed_invoice):
	for i in range(len(tree)):
		if tree[i] == -1:
			print(employees[i].name + " -")
		else:
			print(employees[i].name + " " + employees[tree[i]].name)
		print(len(processed_invoice[i]))
		for j in range(len(processed_invoice[i])):
			print(processed_invoice[i][j].name, end =" ")
		if len(processed_invoice[i]) > 0 : print()

