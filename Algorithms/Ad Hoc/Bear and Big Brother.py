from math import floor, log

a, b = tuple(map(int, input().split()))
print(floor(log(b/a, 3/2)) + 1)