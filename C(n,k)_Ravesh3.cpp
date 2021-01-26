/*
	Soorat soal:
	to khat avval ye q midim.
	to har kodom az q khat badi do ta adad n va k ro midim,
	va shoma bayad be ezaye har khat C(n,k) ro be dast biarid;
	
	preprocess nadarim!
	Hazine javab dadan be har query: maxk

	*** maxk bozorg tarin k ke az vorodi gereftim hast ***

	Hazine kol: q*maxk
*/
#include<bits/stdc++.h>
using namespace std;

int q;

int C(int n,int k){
	int ans=1;
	for(int i=1;i<=k;i++){
		ans*=n-i+1;
		// ans alan bar i bakhsh pazire
		ans/=i;
	}
	return ans;
}

int32_t main(){
	cin>>q;
	for(int i=0;i<q;i++){
		int n,k;
		cin>>n>>k;
		cout<<C(n,k)<<endl;
	}
}