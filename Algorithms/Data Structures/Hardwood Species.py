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
            trees[word] = trees.get(word, 0) + 1
            count += 1
    except EOFError:
        return count

def printAnswer(word):
    print(word, " %.4f" % (trees[word] / totalTrees *100))

while n:
    totalTrees = processTree()
    list(map(printAnswer, trees.keys()))
    trees = {{}
    if n != 1: print()
    n-=1