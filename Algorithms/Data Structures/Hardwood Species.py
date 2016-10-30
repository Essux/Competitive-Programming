n = int(input())
input()
trees = {}
def processTree():
    try:
        count = 0
        while True:
            word = input()
            if word == "":
                return count
            if word not in trees:
                trees[word] = 1
            else:
                trees[word] += 1
            count += 1
    except EOFError:
        return count

while n:
    totalTrees = processTree()
    for a in trees.keys():
        print(a, " %.4f" % (trees[a] / totalTrees *100))
    trees = {}
    if n != 1: print()
    n-=1