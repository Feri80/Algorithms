// In Name Of God
#include <bits/stdc++.h>
#define IB std::ios::sync_with_stdio(0);
#define forn(i,b) for(int i=0 ; i<b ; i++)
#define ford(i,a,b) for(int i=a ; i>=b ; i--)
#define endl "\n"
#define all(x) x.begin(),x.end()
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define po pop_back
#define F first
#define S second
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair <int,int> pii;
const int inf=1e9+10;
const int delta=1e9+7;
const int maxn=1e5+10;
const int base=37;

vector<int>ts;
vector<int>g[maxn], gr[maxn], scc[maxn];
int scc_num[maxn], cnt;
int mark[maxn];
int mark2[maxn];
vector <int> ans;
int s,n,e;


void topol(int u)
{
    mark[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!mark[v])
        {
            topol(v);
        }
    }
    ts.pb(u);
}

void dfs(int u)
{
    mark2[u]=1;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(!mark2[v])
        {
            dfs(v);
        }
    }
    ans.pb(u);
}

void SCC() {
    topol(s);
    reverse(ts.begin(), ts.end());
            dfs(ts[0]);
}
int main()
{
	IB; cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>e>>s;
        for(int i=0;i<maxn;i++)
        {
            g[i].clear();
            gr[i].clear();
        }
        for(int i=0;i<e;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
            gr[v].pb(u);
        }
        SCC();
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }

    }

}






//Written By Farhad Aman
