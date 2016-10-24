nodes, destination = list(map(int, input().split()))
sucesion = list(map(int, input().split()))
graph = {x: set() for x in range(1, nodes+1)}
for i in range(1, 1+len(sucesion)):
	to = i + sucesion[i-1]
	graph[i].add(to)

def dfs(graph, start):
	visited, stack = set(), [start]
	while stack:
		parent = stack.pop()
		visited.add(parent)
		stack.extend(graph[parent] - visited)
	return visited

print('YES' if destination in dfs(graph, 1) else 'NO')