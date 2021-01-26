/*
	Soorat soal:
	to khat avval ye q midim.
	to har kodom az q khat badi do ta adad n va k ro midim,
	va shoma bayad be ezaye har khat C(n,k) ro be dast biarid;

	Hazine preprocess: maxn
	Hazine javab dadan be har query: 1

	*** maxn bozorg tarin n ke az vorodi gereftim hast ***

	Hazine kol: maxn+q
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10+2;

int q,fact[maxn];

void preprocess(){
	fact[0]=1;
	for(int i=1;i<maxn;i++){
		fact[i]=i*fact[i-1];
	}
}

int C(int n,int k){
	return (fact[n]/(fact[n-k]*fact[k]));
}

int32_t main(){
	preprocess();
	cin>>q;
	for(int i=0;i<q;i++){
		int n,k;
		cin>>n>>k;
		cout<<C(n,k)<<endl;
	}
}