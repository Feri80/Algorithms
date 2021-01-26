/*
	LCS Problem Statement: 
	Given two sequences, 
	find the length of longest subsequence present in both of them.
	A subsequence is a sequence that appears in the same relative order,
	but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc
	are subsequences of “abcdefg”.
	So a string of length n has 2^n different possible subsequences.
	Link: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10;

int n,m,dp[maxn][maxn];
string s,t;

int32_t main(){
	cin>>n>>m;
	cin>>s>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n][m]<<endl;
}