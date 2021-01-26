#include <iostream>
using namespace std;
const int maxn=65537+100;
int a[maxn];
int temp[maxn];
int l,m,k;
long long res=0;
void merge(int left,int mid,int right){
    l=left,m=mid+1,k=left-1;
    while(l<=mid && m<=right){
        k+=1;
        if(a[l]>a[m]){
            temp[k]=a[m];
            m++;
        }
        else{
            temp[k]=a[l];
            l++;
        }
    }
    if(l>mid)
        for(int i=0;i<=right-m;i++)
            temp[k+i+1]=a[m+i];
    if(m>right)
        for(int i=0;i<=mid-l;i++)
            temp[k+i+1]=a[l+i];
    for(int i=left;i<=right;i++)
        a[i]=temp[i];
}

void mergesort(int left,int right){
    int mid;
    if(left==right)
        return;
    if(left!=right){
        mid=(left+right)/2;
        mergesort(left,mid);
        mergesort(mid+1,right);
        merge(left,mid,right);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    mergesort(1,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl;

    return 0;
}