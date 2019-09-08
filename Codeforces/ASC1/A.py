import math

input = open("china.in", "r")
output = open("china.out", "w")
x = int(input.readline())
k = x // 2

while math.gcd(x, k) != 1 and k > 1:
    k -= 1
output.write(str(k))


