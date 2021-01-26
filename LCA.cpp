// In Name Of God

#include <bits/stdc++.h>
#define IB std::ios::sync_with_stdio(0);
#define forn(i,b) for(int i=0 ; i<b ; i++)
#define endl "\n"
#define all(x) x.begin(),x.end()
#define pb push_back
#define po pop_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
const int mod=1e9+7;
const ll inf=1e18;
const int maxn=1e5+10;
const double eps=1e-7;
const double pi=3.14159265359;
int pr[25][maxn],dis[maxn],n;

void add(int u)
{
    n++;
    pr[0][n]=u;
    for(int i=1;i<20;i++)
    {
        pr[i][n]=pr[i-1][pr[i-1][n]];
    }
    dis[n]=dis[u]+1;
}

int lca(int u,int v)
{
    if(dis[u]<dis[v])
    {
        swap(u,v);
    }
    while(dis[u]>dis[v])
    {
        int h=log2(dis[u]-dis[v]);
        u=pr[h][u];
    }
    if(u==v)
    {
        return u;
    }
    for(int i=19;i>=0;i--)
    {
        if(pr[i][u]!=pr[i][v])
        {
            u=pr[i][u];
            v=pr[i][v];
        }
    }
    return pr[0][u];
}

int main()
{
	IB; cin.tie(0); cout.tie(0);

}

//Written By Farhad Aman






