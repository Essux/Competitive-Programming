t = int(input())
for i in range(0, t):
    n = int(input())
    static_n = n
    digits = set()
    while len(digits)<10 and n:
        digits.update(map(int, str(n)))
        n += static_n
    print("Case #", i+1, ':', sep='', end=' ')
    if (n == 0):
        print ('INSOMNIA')
    else:
        print(n-static_n)