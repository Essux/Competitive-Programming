from math import factorial as f

def rep_perm(a, b, n):
    return f(n) // (f(a) * f(b))


memo = [0 for x in range(106)]
for i in range(4, 104, 2):
    a = i // 4
    b = (i % 4) // 2
    ans = 0
    c = 0
    while (a-b)//3 >= c:
        ans += rep_perm(a-c, b+2*c, (b+2*c) + (a-c) )**2
        c += 1
    memo[i] = ans

P = int(input())
for i in range(P):
    ncase, n = tuple(map(int, input().split()))
    print(ncase, memo[n])