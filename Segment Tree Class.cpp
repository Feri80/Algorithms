#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public :
        int sum=0;
        node *lch , *rch;
        int left, right ;
        node(int l, int r){
            left = l;
            right = r;
            if(left==right){
                return;
            }
            int mid = (left+right)/2;
            lch = new node(left,mid);
            rch = new node(mid+1,right);
        }
        void insert(int x, int i){
            if(!(i >= left && i<= right)){
                return;
            }
            sum += x;
            if(left==right)return;
            lch->insert(x,i);
            rch->insert(x,i);
        }
        int get(int l, int r){
            if(right<l || r<left){
                return 0;
            }
            if(left>=l && right<=r){
                return sum;
            }
            if(left==right)return sum;
            return lch->get(l,r) + rch->get(l,r);
        }
};

node *root;

int main()
{
    //root->insert(x,i);
    /////////////////////////////////////////////
   int n;
   cin>>n;
   root = new node(1, n);
   for(int i=1;i<=n;i++){
        int a;
        cin>> a;
        //cout<<a<<" "<<i<<endl;
        root->insert(a,i);
   }
   //x = new st(1,n);
   int q;
   cin>>q;
   vector<int> ans;
   for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        ans.push_back(root->get(l,r));
   }
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
   }
   return 0;
}
