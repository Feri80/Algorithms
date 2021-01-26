#include <bits/stdc++.h>
#define IB std::ios::sync_with_stdio(0);
#define FOR(i,b) for(int i=0 ; i<b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define all(x) x.begin(),x.end()
#define sq(a) (a)*(a)
#define pu push_back
#define po pop_back 
#define F first
#define S second
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair <int,int> pii;
const ll inf=10e9+10;

const int maxn=10e5;
int n,m;
vector <pair<int , pii> > G;
vector <pii> mst;
int par[maxn];

int root(int a)
{
	if(par[a]==a) return a;
	par[a]=root(par[a]);
	return root(par[a]);
}

void u(int a,int b)
{
	par[root(a)]=root(b);
}

void krus()
{
	sort(all(G));
	mst.clear();
	for(int i=0;i,n;i++)
	{
		par[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		int f=G[i].S.F;
		int t=G[i].S.S;
		if(root(f)!=root(t))
		{
			mst.pu(G[i].S);
			u(f,t);
		}
	}	
}

int main()
{
	IB; cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	G.clear();
	for(int i=0;i<m;i++)
	{
		int f,t,w;
		cin>>f>>t>>w;
		G.pu(make_pair( w , pii(f,t) ) );
	}
	krus();
}


