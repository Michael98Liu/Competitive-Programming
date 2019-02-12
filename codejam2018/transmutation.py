#Dinic Algorithm

#build level graph by using BFS
def Bfs(C, F, s, t):  # C is the capacity matrix
        n = len(C)
        queue = []
        queue.append(s)
        global level
        level = n * [0]  # initialization
        level[s] = 1
        while queue:
            k = queue.pop(0)
            for i in range(n):
                    if (F[k][i] < C[k][i]) and (level[i] == 0): # not visited
                            level[i] = level[k] + 1
                            queue.append(i)
        return level[t] > 0

#search augmenting path by using DFS
def Dfs(C, F, k, cp):
        tmp = cp
        if k == len(C)-1:
            return cp
        for i in range(len(C)):
            if (level[i] == level[k] + 1) and (F[k][i] < C[k][i]):
                f = Dfs(C,F,i,min(tmp,C[k][i] - F[k][i]))
                F[k][i] = F[k][i] + f
                F[i][k] = F[i][k] - f
                tmp = tmp - f
        return cp - tmp

#calculate max flow
#_ = float('inf')
def MaxFlow(C,s,t):
        n = len(C)
        F = [n*[0] for i in range(n)] # F is the flow matrix
        flow = 0
        while(Bfs(C,F,s,t)):
               flow = flow + Dfs(C,F,s,100000)
        return flow

#-------------------------------------
# make a capacity graph
# node   s   o   p   q   r   t
t = int(input())

for _ in range(t):
    n = int(input())
    graph = [[0 for i in range(n)] for j in range(n)]
    flow = [[0,0] for i in range(n)]
    for i in range(n):
        flow[i] = [int(x) for x in input().split()]

    capacity = [int(x) for x in input().split()]

    for i in range(len(flow)):
        graph[flow[i][0]-1][i] = capacity[flow[i][0]-1]
        graph[flow[i][1]-1][i] = capacity[flow[i][1]-1]


    source = n - 1
    sink = 0
    max_flow_value = MaxFlow(graph, source, sink)
    print("max_flow_value is", max_flow_value)
