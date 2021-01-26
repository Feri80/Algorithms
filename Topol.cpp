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

const ll maxn=10e5+10;
vector <ll> G[maxn];
vector <ll> topol;
ll deg[maxn];
ll n,m;



int main()
{
	IB; cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].pu(v);
		deg[v]++;
	}
	
	for(int i=0;i<n;i++)
	{
		if(deg[i]==0) topol.pu(i);
	}
	for(int i=0;i<topol.size();i++)
	{
		int u=topol[i];
		for(int j=0;j<G[u].size();j++)
		{
			int v=G[u][j];
			deg[v]--;
			if(deg[v]==0)
			{
				topol.pu(v);
			}
		}
	}
	
	for(int i=0;i<topol.size();i++)
	{
		cout<<topol[i]<<" ";
	}
	
}


