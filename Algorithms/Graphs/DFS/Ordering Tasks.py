while True:
    try:
        nodes, edges = list(map(int, input().split()))
        if nodes == 0 and edges == 0:
            break
        graph = {x: set() for x in range(1, nodes+1)}
        for i in range(edges):
            f, t = list(map(int, input().split()))
            graph[f].add(t)
        order = []
        state = [0 for x in range(nodes)]


        def dfs(graph, start):
            state[start-1] = 1
            for currSon in graph[start]:
                if state[currSon-1] == 0:
                    dfs(graph, currSon)
            order.append(start)

        for i in range(len(state)):
            if state[i] == 0:
                dfs(graph, i+1)
        for a in reversed(order):
            print(a, end=' ')
        print()
    except (EOFError, ValueError):
        break