#include <bits/stdc++.h>
#define IB std::ios::sync_with_stdio(0);
#define pu push_back
#define po pop_back
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair <int,int> pii;
const ll inf=10e9+10;
const ll maxn=10e5;
ll mark[maxn];
vector <int> adj[maxn];
ll n,m;

void dfs(int u)
{
	mark[u]=1;
	for(auto x:adj[u])
	{
		if(!mark[x])
		{
			dfs(x);
		}
	}
}
int main()
{
	IB; cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		adj[u].pu(v);
		adj[v].pu(u);
	}
}


