/*
	Soorat soal:
	to khat avval ye q midim.
	to har kodom az q khat badi do ta adad n va k ro midim,
	va shoma bayad be ezaye har khat baghimande C(n,k) bar 1e9+7 (ye addad avval) ro be dast biarid;

	Hazine preprocess: maxn^2
	Hazine javab dadan be har query: 1
	
	*** maxn bozorg tarin n ke az vorodi gereftim hast ***

	Hazine kol: maxn^2+q
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10,M=1e9+7;

int q,C[maxn][maxn];

void preprocess(){
	for(int i=0;i<maxn;i++){
		C[i][i]=1;
		C[i][0]=1;
	}
	for(int i=1;i<maxn;i++){
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
		}
	}
}

int32_t main(){
	preprocess();
	cin>>q;
	for(int i=0;i<q;i++){
		int n,k;
		cin>>n>>k;
		cout<<C[n][k]<<endl;
	}
}