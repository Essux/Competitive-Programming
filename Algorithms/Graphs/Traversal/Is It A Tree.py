nodes, edges = list(map(int, input().split()))
graph = {n: set() for n in range(1, nodes+1)}
for i in range(edges):
    f, t = list(map(int, input().split()))
    graph[f].add(t)
    graph[t].add(f)


def dfs(graph, start):
    state[start-1] = 1
    for currSon in graph[start]:
        if state[currSon-1] == 0:
            dfs(graph, currSon)
        elif state[currSon-1] == 2:
            return False
    state[start-1] = 2
    return True

result = True
for node in graph.keys():
    state = [0 for x in range(nodes)]
    result = result and dfs(graph, node)
if result:
    print("YES")
else:
    print("NO")