n = int(input())

for i in range(n):
    a = int(input())
    ans = (a * (a+1) * (2*a + 4)) // 6
    ans %= 10**9 + 7
    print('Case {}: {}'.format(i+1, ans))