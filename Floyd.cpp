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

const ll maxn=10*1000+10;
ll dis[maxn][maxn];
ll n,m;

void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}

int main()
{
	IB; cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		fill(dis[i],dis[i]+n,inf);
		dis[i][i]=0;
	}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
	//	dis[u][v]=w; // agar graph jahat dar bood
	dis[u][v]=w;     dis[v][u]=w;	// agar bi jahat bood     
	}
	floyd();
	cout<<dis[2][3];
}


