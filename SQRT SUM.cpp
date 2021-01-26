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
int a[maxn],b[maxn],n,len;

void pre()
{
    len=sqrt(n+.0)+1;
    forn(i,n)
    {
        b[i/len]+=a[i];
    }
}

int query(int l,int r)
{
    int sum=0;
    for(int i=l;i<=r;)
    {
        if(i%len==0 and i+len-1<=r)
        {
            sum+=b[i/len];
            i+=len;
        }
        else
        {
            sum+=a[i];
            i++;
        }
    }
    return sum;
}

int main()
{
	IB; cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n)
    {
        cin>>a[i];
    }
    pre();
    cout<<query(3,7);
}

//Written By Farhad Aman






