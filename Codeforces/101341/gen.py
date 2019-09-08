from random import choice
import sys
s = "abcdefghijklmnopqrstuvwxyz"
for _ in range(int(sys.argv[1])):
	print(choice(s), end='')
for _ in range(int(sys.argv[2])):
	print("happiness", end='')
