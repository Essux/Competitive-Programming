from collections import deque

row = [1]
print(1)
stop = False
while not stop:
    nextRow = deque()
    for i in range(len(row)+1):
        if i==0: left = 0
        else: left = row[i-1]
        if i>=len(row): right = 0
        else: right = row[i]
        n = left+right
        if n >= 10**60:
            stop = True
        nextRow.append(n)
    row = nextRow
    end = ' '
    for i, a in enumerate(row):
        if i == len(row)-1: end = ''
        print(a, end=end)
    print()