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
vector <ll> G[maxn];
vector <ll> l;
ll dis[maxn];
ll n,m;

void bfs(ll s)
{
	for(int i=0;i<maxn;i++)
	{
		dis[i]=maxn+1;
	}
	dis[s]=0;
	l.clear();
	l.push_back(s);
	for(int i=0;i<l.size();i++)
	{
		ll u=l[i];
		for(int j=0;j<G[u].size();j++)
		{
			ll v=G[u][j];
			if(dis[v]>dis[u]+1)
			{
				l.push_back(v);
				dis[v]=dis[u]+1;
			}
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
		G[u].push_back(v);
		G[v].pu(u);
	}
	ll s;
		cin>>s;
		bfs(s);
	for(int i=0;i<n;i++)
	{
		cout<<dis[i]<<" ";
	}
}


