#include <bits/stdc++.h>
#define IB std::ios::sync_with_stdio(0);
#define pu push_back
#define po pop_back
#define F first
#define S second

using namespace std;
typedef long long int ll;
typedef pair <int,int> pii;
const int inf=1000*1000*1000;

const int maxn=1000*100+10;
int n,m;
vector <pii> edge;
vector <int> w;
ll dis[maxn];

void bellman(int s)
{
	dis[s] = 0;
    	for(int i=0; i<n; ++i)
    		if(i!=s)
    			dis[i] = inf;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<(int)edge.size();j++)
		{
			int u=edge[j].first;
			int v=edge[j].second;
			dis[v]=min(dis[v],dis[u]+w[j]);
		}
	}
}

int main()
{
	IB; cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,z;
		cin>>u>>v>>z;
		edge.push_back(pii(u,v));
		w.push_back(z);
	}
	
	int s;
	cin>>s;
	bellman(s);
	for(int i=0;i<n;i++)
	{
		cout<<dis[i]<<endl; 
	}
	
}


