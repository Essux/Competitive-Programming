N = int(input())
for i in range(N):
    A = int(input())
    nums = list(map(int, input().split()))[1:]
    wonder = True
    for num in nums:
        wonder = wonder and (A % num == 0)
    print(A, end=' - ')
    print('Wonderful.' if wonder else 'Simple.')