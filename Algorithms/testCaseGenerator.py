import random
testCases = 3
#print(testCases)
for a in range(0, testCases):
    n = random.randint(1, 200000)
    print(n)
    for i in range(0, n):
        print(random.randint(0, 200000))
    actions = ['S', 'M']
    for i in range(0, 100):
        action = random.choice(actions)
        print(action, end=' ')
        if action == 'S':
            print(random.randint(1, n), random.randint(0, 1000))
        else:
            x = random.randint(1, n)
            y = random.randint(x, n)
            print(x, y)
    print("END")
print(0)