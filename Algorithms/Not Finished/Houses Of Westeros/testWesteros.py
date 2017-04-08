import random as r
n = r.randint(30, 30)
print (n)
mat = [[r.choice(['D']) for x in range(0, n)] for y in range(0, n)]
for i in range(0, n):
    for j in range(i, n):
        mat[i][j] =mat[j][i]

for i in range(0, n):
    for j in range(i, n):
        if i == j:
            mat[i][j] = 'S'

for i in range(0, n):
    for j in range(0, n):
        print(mat[i][j], end='')
    print()