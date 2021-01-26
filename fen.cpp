// In Name Of God

#include <bits/stdc++.h>
#define IB std::ios::sync_with_stdio(0);
#define forn(i,b) for(int i=0 ; i<b ; i++)
#define endl "\n"
#define all(x) x.begin(),x.end()
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define po pop_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
const ll mod=1e9+7;
const ll inf=1e9+111;
const int maxn=1e5+10;
int fen[1000],a[1000],n;

void update(int x,int delta)
{
      for(;x<=n;x+=x&-x)
        fen[x]+=delta;
}
int query(int x)
{
     int sum=0;
     for(;x>0;x-=x&-x)
        sum+=fen[x];
     return sum;
}

int main()
{
	IB; cin.tie(0); cout.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    cout<<query(10)<<endl;
    update(9,5);
    cout<<query(10);
}

//Written By Farhad Aman








