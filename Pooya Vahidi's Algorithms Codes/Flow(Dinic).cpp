//O(V^2*E) no-base
struct Edge {
    int to,reverseIndex,cap,flow;
};

int n,m,s,t,maxFlow,dis[MAX_N];
vector<Edge>g[MAX_N];
queue<int>q;

void addEdge(int u, int v, int cap) {
    Edge x,y;
    x.to = v;
    y.to = u;
    x.cap = cap;
    y. cap = 0;
    x.flow = y.flow = 0;
    x.reverseIndex = g[v].size();
    y.reverseIndex = g[u].size();
    g[u].push_back(x);
    g[v].push_back(y);
}

bool bfs() {
    memset(dis, 31, sizeof dis)
    while(q.size()) q.pop();
    q.push(s);
    dis[s] = 0;
    while(q.size() > 0) {
        int v = q.front();
        q.pop();
        for(Edge x:g[v]) {
            int u = x.to;
            if(dis[u] == INF && x.flow < x.cap) {
                dis[u] = dis[v]+1;
                q.push(u);
            }
        }
    }
    return (dis[t] != INF);

}

int dfs(int v,int f) {
    if(v == t)
        return f;
    for(int i = 0 ; i < g[v].size() ; i++) {
        Edge &x = g[v][i];
        int u = x.to;
        if(x.cap <= x.flow) continue;
        if(dis[u] == dis[v]+1) {
            int tmp = dfs(u,min(f,x.cap-x.flow));
            if(tmp > 0) {
                x.flow += tmp;
                g[u][x.reverseIndex].flow -= tmp;
                return tmp;
            }
        }
    }
    return 0;
}

void dinic() {
    while(bfs()) {
        while(int tmp = dfs(s,INF))
            maxFlow += tmp;
    }

}
