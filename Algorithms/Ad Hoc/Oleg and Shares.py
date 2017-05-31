N, K= tuple(map(int, input().split()))
nums = list(map(int, input().split()))
m = min(nums)
print(-1 if [0 for x in nums] != [(x-m) % K for x in nums] else sum([(x-m) // K for x in nums]), end='')