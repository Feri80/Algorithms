//In The Name of Beauty
//Go for 9
#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector<ll> vll;
#define IB std::ios::sync_with_stdio(0);
#define pb(x) push_back(x);
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define F first
#define S second
//ll const MAXN = 1e5 + 8;
//ll const LGR  = 33;
ll const ZIAD = 15;

//vll G[MAXN];
vll people[MAXN];
vll mmin [MAXN][LGR];
//ll par[MAXN][LGR];
//ll height[MAXN];
vll temp , temp1 , temp2;

void mergee()
{
    vll ans;
    vll s1 = temp1;
    vll s2 = temp2;
    ll i = 0 , j = 0;
    while(ans.size() < ZIAD - 1)
    {
        if(i == s1.size() || j == s2.size())break;
        if(s1[i] < s2[j])
        {
            ans.pb(s1[i]);
            i++;
        }
        else
        {
            ans.pb(s2[j]);
            j++;
        }
    }
    while(j < s2.size())
    {
        if(ans.size() == ZIAD - 1)break;
        ans.pb(s2[j]);
        j++;
    }
    while(i < s1.size())
    {
        if(ans.size() == ZIAD - 1)break;
        ans.pb(s1[i]);
        i++;
    }
    temp = ans;
}

//void dfs(ll v,ll P)
//{
//    if(P == -1)height[v] = 1;
//    else height[v] = height[P] + 1;
//    for(ll i = 0;i < people[v].size();i++)
//    {
        if(mmin[v][0].size() >= ZIAD - 1)break;
        mmin[v][0].pb(people[v][i]);
//    }
//    for(ll i = 0;i < G[v].size();i++)
//    {
//        ll u = G[v][i];
//        if(u == P)continue;
//        dfs(u,v);
//        par[u][0] = v;
//    }
//}

//void dfs_lca(ll v,ll P)
//{
//    for(ll i = 1;i < LGR;i++)
//    {
//        ll u = par[v][i - 1];
//        par[v][i] = par[u][i - 1];
        temp1 = mmin[v][i - 1];
        temp2 = mmin[u][i - 1];
        mergee();
        mmin[v][i] = temp;
//    }
//    for(ll i = 0;i < G[v].size();i++)
//    {
//        if(G[v][i] == P)continue;
//        dfs_lca(G[v][i],v);
//    }
//}

void solve(ll v,ll u,ll k)
{
//    if(height[v] > height[u])swap(v,u);
//    ll h = height[u] - height[v];
    vll ans;
//    for(ll i = LGR - 1;i >= 0;i--)
//    {
//        if(h & (1ll << i))
//        {
//            h -= (1ll << i);
            temp1 = ans;
            temp2 = mmin[u][i];
            mergee();
            ans = temp;
//            u = par[u][i];
//        }
//    }
    if(u == v)
    {
        temp1 = ans;
        temp2 = mmin[u][0];
        mergee();
       k = min(k,(ll)ans.size());
//        return v;
    }
//    for(ll i = LGR - 1;i >= 0;i--)
//    {
//        if(par[v][i] && par[v][i] != par[u][i])
//        {
            temp1 = ans;
            temp2 = mmin[u][i];
            mergee();
            ans = temp;
           temp1 = ans;
            temp2 = mmin[v][i];
            mergee();
            ans = temp;
//            v = par[v][i];
//            u = par[u][i];
//        }
//    }
    temp1 = ans;
    temp2 = mmin[v][1];
    mergee();
    ans = temp;
    temp1 = ans;
    temp2 = mmin[u][0];
    mergee();
// return par[v][0]
}

int main()
{
    IB;
    cin.tie(0);
    cout.tie(0);
    ll n , m, q;
    cin >> n >> m >> q;
    ll f , s;
//    for(ll i = 0;i < n - 1;i++)
//    {
//        cin >> f >> s;
//        G[f].pb(s);
//        G[s].pb(f);
//    }
    ll t;
    for(ll i = 1;i <= m;i++)
    {
        cin >> t;
        people[t].pb(i);
    }
    for(ll i = 1;i <= n;i++)
    {
        if(people[i].size())
        {
            sort(people[i].begin(),people[i].end());
        }
    }
   // dfs(1,-1);
   // dfs_lca(1,-1);
    for(ll i = 0;i < q;i++)
    {
        cin >> f >> s >> t;
        solve(f,s,t);
        t = min(t,(ll)temp.size());
        cout << t << " ";
        for(ll j = 0;j < t;j++)
        {
            cout << temp[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//Written by M_H_H_7