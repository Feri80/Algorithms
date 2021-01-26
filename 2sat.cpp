func dfsFirst(vertex v):
    marked[v] = true
    for each vertex u adjacent to v do:
        if not marked[u]:
            dfsFirst(u)
    stack.push(v)

func dfsSecond(vertex v):
    marked[v] = true
    for each vertex u adjacent to v do:
        if not marked[u]:
            dfsSecond(u)
    component[v] = counter

for i = 1 to n do:
    addEdge(not x[i], y[i])
    addEdge(not y[i], x[i])
for i = 1 to n do:
    if not marked[x[i]]:
        dfsFirst(x[i])
    if not marked[y[i]]:
        dfsFirst(y[i])
    if not marked[not x[i]]:
        dfsFirst(not x[i])
    if not marked[not y[i]]:
        dfsFirst(not y[i])

set all marked values false
counter = 0
flip directions of edges // change v -> u to u -> v

while stack is not empty do:
    v = stack.pop
    if not marked[v]
        counter = counter + 1
        dfsSecond(v)

for i = 1 to n do:
    if component[x[i]] == component[not x[i]]:
        it is unsatisfiable
        exit
    if component[y[i]] == component[not y[i]]:
        it is unsatisfiable
        exit

it is satisfiable
exit
