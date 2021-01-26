#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 100000+10;
const int inf = 1e9+10;

int n,m;
vector <pii> G[MAX_N];

int dis[MAX_N];

void dijkstra(int sou){
	for(int i = 1 ; i <= n ; i++){
		dis[i] = inf;
	}
	dis[sou] = 0;
	set <pii> s;
	s.clear();
	for(int i = 1 ; i <= n ; i++){
		s.insert( pii(dis[i], i) );
	}
	while(s.size()){
		int u = ( *(s.begin()) ).second;
		s.erase( s.begin() );
		for(int i = 0 ; i < G[u].size() ; i++){
			int v = G[u][i].first;
			int w = G[u][i].second;
			if(dis[v] > dis[u] + w){
				s.erase( pii(dis[v], v) );
				dis[v] = dis[u] + w;
				s.insert( pii(dis[v], v) );
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back( pii(v, w) );
		G[v].push_back( pii(u, w) );
	}
	int sou;
	cin >> sou;
	dijkstra(sou);
	for(int i = 1 ; i <= n ; i++){
		cout << i << " : " << dis[i] << endl;
	}
}
