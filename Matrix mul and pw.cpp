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
const int maxn=1e2+7;
const double eps=1e-7;
const double pi=3.14159265359;
ll n,m;

struct Matrix
{
    ll n,m,M[maxn][maxn];
    Matrix(ll x,ll y,ll t=0)
    {
        n=x;
        m=y;
        build(t);
    }
    void build(ll x)
    {
        if(x==-1)
        {
            for(ll i=0;i<n;i++)
            {
                M[i][i]=1;
            }
        }
        else
        {
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<m;j++)
                {
                    M[i][j]=x;
                }
            }
        }
    }
    Matrix operator *(const Matrix &N)
    {
        Matrix temp=Matrix(n,N.m);
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                for(ll k=0;k<N.m;k++)
                {
                    temp.M[i][k]=(temp.M[i][k]+M[i][j]*N.M[j][k])%mod;
                }
            }
        }
        return temp;
    }
};

Matrix pw(ll p)
{
    Matrix temp=Matrix(m,m);
    for(ll i=0;i<m-1;i++)
    {
        temp.M[i+1][i]=1;
    }
    temp.M[0][m - 1]=1;
    temp.M[m-1][m-1]=1;
    Matrix ans=Matrix(m,m,-1);
    while(p)
    {
        if(p&1)
        {
            ans=ans*temp;
        }
        p/=2;
        temp=temp*temp;
    }
    return ans;
}

int main()
{
    IB; cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(n<m)
    {
        cout<<1;
        return 0;
    }
    Matrix ans=Matrix(1,m,1);
    ans=ans*pw(n-m+1);
    cout<<ans.M[0][m-1];
}


//Written By Farhad Aman






