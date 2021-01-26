//O(V^3) 0-base
struct Edge {
	int from, to, cap, flow, index;
	Edge(int from, int to, int cap, int flow, int index) :
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};
int n, m, s, t, maxFlow, dist[MAX_N], active[MAX_N], CNT[2*MAX_N];
vector<Edge> g[MAX_N];
ll excess[MAX_N];
queue<int> q;
void CLEAR() {
	maxFlow = 0;
	while(q.size()) q.pop();
	memset(CNT, 0, sizeof CNT);
	for(int i = 0 ; i < MAX_N ; i++) {
		g[i].clear();
		dist[i] = active[i] = excess[i] = 0;
	}
}
void AddEdge(int from, int to, int cap) {
	g[from].push_back(Edge(from, to, cap, 0, g[to].size()));
	if (from == to) g[from].back().index++;
	g[to].push_back(Edge(to, from, 0, 0, g[from].size() - 1));
}
void Enqueue(int v) {
	if (!active[v] && excess[v] > 0) { active[v] = true; q.push(v); }
}
void Push(Edge &e) {
	int amt = int(min(excess[e.from], ll(e.cap - e.flow)));
	if (dist[e.from] <= dist[e.to] || amt == 0) return;
	e.flow += amt;
	g[e.to][e.index].flow -= amt;
	excess[e.to] += amt;
	excess[e.from] -= amt;
	Enqueue(e.to);
}
void Gap(int k) {
	for (int v = 0; v < n; v++) {
		if (dist[v] < k) continue;
		CNT[dist[v]]--;
		dist[v] = max(dist[v], n+1);
		CNT[dist[v]]++;
		Enqueue(v);
	}
}
void Relabel(int v) {
	CNT[dist[v]]--;
	dist[v] = 2*n;
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i].cap - g[v][i].flow > 0)
			dist[v] = min(dist[v], dist[g[v][i].to] + 1);
	CNT[dist[v]]++;
	Enqueue(v);
}
void Discharge(int v) {
	for (int i = 0; excess[v] > 0 && i < g[v].size(); i++) Push(g[v][i]);
	if (excess[v] > 0) {
		if (CNT[dist[v]] == 1)
			Gap(dist[v]);
		else
			Relabel(v);
	}
}
void push_relabel() {
	CNT[0] = n-1;
	CNT[n] = 1;
	dist[s] = n;
	active[s] = active[t] = true;
	for (int i = 0; i < g[s].size(); i++) {
		excess[s] += g[s][i].cap;
		Push(g[s][i]);
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		active[v] = false;
		Discharge(v);
	}
	ll totflow = 0;
	for (int i = 0; i < g[s].size(); i++) totflow += g[s][i].flow;
	maxFlow = totflow;
}
