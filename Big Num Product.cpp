#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_A = 100+10;
const int MAX_B = 100+10;
const int MAX_C = 200+10;

int a[MAX_A], b[MAX_B], c[MAX_C];
int cnta,  cntb;

int main(){
	string A,B;
	cin>>A>>B;
	cnta = A.size();
	cntb = B.size();
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	for(int i = 0 ; i < cnta ; i++){
		a[i] = A[i]-'0';
	}
	for(int i = 0 ; i < cntb ; i++){
		b[i] = B[i]-'0';
	}
	
	for(int i = 0 ; i < cntb ; i++){
		int k = i;
		for(int j = 0; j < cnta ; j++){
			int l = j + k;
			c[l] += a[j]*b[i];
		}
	}
	for(int i = 0 ; i < MAX_C-1 ; i++){
		c[i+1] += c[i]/10;
		c[i] %=10;
	}
	int cntc = MAX_C-1;
	while((cntc > 0) && (c[cntc] == 0)){
		cntc --;
	}
	cntc ++;
	for(int i = cntc - 1 ; i >= 0 ; i--){
		cout<<c[i];
	}
	cout<<endl;
}
