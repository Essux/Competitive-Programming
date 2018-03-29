def fib(n):
    if n == 0:
        return (0, 1)
    else:
        a, b = fib(n//2)
        a %= 10**9
        b %= 10**9
        c = a * (b * 2 - a)
        d = a * a + b * b
        if n % 2 == 0: return (c, d)
        else: return (d, c+d)


n = int(input())
for i in range(n):
    a, m = tuple(map(int, input().split()))
    print(a, fib(m)[0]%10**9)