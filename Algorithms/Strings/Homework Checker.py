from sys import stdin

count = 0
for line in stdin.read().splitlines():
    if '+' in line: sep = '+'
    else: sep = '-'
    op, res = line.split('=')
    if res == '?': continue
    res = int(res)
    op = list(map(int, op.split(sep)))
    if sep == '+' and op[0]+op[1]==res: count += 1
    if sep == '-' and op[0]-op[1]==res: count += 1
print(count)