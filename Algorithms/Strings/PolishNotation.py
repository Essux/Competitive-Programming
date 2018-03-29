# Polish Notation Generator
def process(line):
    if len(line) == 1:
        return line
    else:
        line = line[1:-1]
        oparen, cparen= 0, 0
        for j in range(len(line)):
            if line[j] == '(':
                oparen += 1
                continue
            elif line[j] == ')':
                cparen += 1
                continue
            if oparen == cparen:
                if line[j] in ['+', '-', '*', '/', '^']:
                    pos = j
                    break
        return process(line[:j]) + process(line[j + 1:]) + line[j]

for i in range(int(input())):
    print(process(input()))
