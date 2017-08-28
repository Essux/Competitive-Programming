from math import factorial as fact
from math import inf

N = int(input())
nums = list(map(int, input().split(' ')))
mins = [inf, inf, inf]
for a in nums:
    if a < mins[0]:
        mins[2] = mins[1]
        mins[1] = mins[0]
        mins[0] = a
    elif a < mins[1]:
        mins[2] = mins[1]
        mins[1] = a
    elif a < mins[2]:
        mins[2] = a

if mins[0] == mins[1]:
    if mins[1] == mins[2]:
        reps = {mins[0] : 3}
    else:
        reps = {mins[0] : 2, mins[2] : 1}
else:
    if mins[1] == mins[2]:
        reps = {mins[0] : 1, mins[1]: 2}
    else:
        reps = {mins[0] : 1, mins[1]: 1, mins[2] : 1}

ans = 1
for key, m in reps.items():
    n = nums.count(key)
    ans *= fact(n) / (fact(m) * fact(n - m))

print(int(ans))