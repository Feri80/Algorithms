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
int st[maxn][25],a[maxn],n,lg[maxn];


void precalc()
{
    for(int i=0;i<n;i++)
    {
        st[i][0]=a[i];
    }
    for(int j=1;j<=25;j++)
    {
        for(int i=0;i+(1<<j)<=n;i++)
        {
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }
    lg[1]=0;
    lg[2]=1;
    for(int i=3;i<maxn;i++)
    {
        lg[i]=lg[i/2]+1;
    }
}



int rmq(int l,int r)
{
    int j=lg[r-l+1];
    return min(st[l][j],st[r-(1<<j)+1][j]);
}


int main()
{
	IB; cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n)
    {
        cin>>a[i];
    }
    precalc();
    cout<<rmq(0,9)<<endl;
    cout<<rmq(0,4)<<endl;
    cout<<rmq(5,9)<<endl;
    cout<<rmq(3,7)<<endl;
    cout<<rmq(1,1);

}

//Written By Farhad Aman






