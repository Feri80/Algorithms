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
const ll mod=1e9+7;
const ll inf=1e18;
const int maxn=1e5+10;
const double eps=1e-7;
const double pi=3.14159265359;

int phi(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
            }
            res-=res/i;
        }
    }
    if(n>1)
    {
        res-=res/n;
    }
    return res;
}

int main()
{
	IB; cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    cout<<phi(n);
}

//Written By Farhad Aman






