//In The Name of Beauty
//Go for 9
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define IB std::ios::sync_with_stdio(0);
#define pb(x) push_back(x);
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define F first
#define S second
ll const MAXN = 5e6 + 8;
ll const INF  = 1e12 + 8;
ll const delta = 1e9+7;
ll fac[MAXN];
ll inv[MAXN];

int g(int n)
{
    return n^(n>>1);
}

ll poww(ll a,ll b)
{
    if(!b)return 1;
    ll x = poww(a,b / 2);
    if(b % 2)return ((((x * x) % delta) * a) % delta);
    return ((x * x) % delta);
}
void pre()
{
    fac[0] = inv[0] = 1;
    for(ll i = 1;i < MAXN;i++)
    {
        fac[i] = (fac[i - 1] * i) % delta;
        inv[i] = poww(fac[i],delta - 2);
    }
}
ll C(ll r,ll n)
{
    if(r > n)return 0;
    return ((((fac[n] * inv[r]) % delta) * inv[n - r]) % delta);
}
int main()
{
    pre();
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<C(j,i)%2<<" ";
        }
        cout<<endl;
    }
}
