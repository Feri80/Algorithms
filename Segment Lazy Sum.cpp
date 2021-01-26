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
int seg[maxn*4];
int lazy[maxn*4];
int a[maxn];

void build(int id,int l,int r)
{
    if(l>r)
    {
        return;
    }
    if(l==r)
    {
        seg[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    seg[id]=seg[id*2]+seg[id*2+1];
}

void relax(int id,int l,int r)
{
    if(l>r)
    {
        return;
    }
    if(lazy[id]!=0)
    {
        seg[id]+=lazy[id];
        if(l!=r)
        {
            lazy[id*2]+=lazy[id];
            lazy[id*2+1]+=lazy[id];
        }
        lazy[id]=0;
    }
}

void update(int id,int l,int r,int s,int e,int val)
{
    relax(id,l,r);
    if(l>r or l>e or r<s)
    {
        return;
    }

    if(l>=s and r<=e)
    {
        seg[id]+=val;
        if(l!=r)
        {
            lazy[id*2]+=val;
            lazy[id*2+1]+=val;
        }
        return;
    }

    int mid=(l+r)/2;
    update(id*2,l,mid,s,e,val);
    update(id*2+1,mid+1,r,s,e,val);
    seg[id]=seg[id*2]+seg[id*2+1];
}

int query(int id,int l,int r,int s,int e)
{
    if(l>r or l>e or r<s)
    {
        return 0;
    }

    relax(id,l,r);

    if(l>=s and r<=e)
    {
        return seg[id];
    }
    int mid=(l+r)/2;
    int q1=query(id*2,l,mid,s,e);
    int q2=query(id*2+1,mid+1,r,s,e);
    int res=q1+q2;
    return res;
}

int main()
{
	IB; cin.tie(0); cout.tie(0);
	int n;
    cin>>n;
    forn(i,n)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    cout<<"ha"<<endl;
    cout<<query(1,0,n-1,0,2)<<endl;
    update(1,0,n-1,1,3,10);
    cout<<query(1,0,n-1,0,2);
}

//Written By Farhad Aman






