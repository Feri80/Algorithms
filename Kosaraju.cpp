#include <iostream>
#include <vector>
using namespace std;
int n,m;
const int N=1000;
vector <int>g[N];
vector <int> bg[N];
vector <int> myStack;
int comps;
bool used[N];
void dfs(int a){
	used[a]=true;
	for(int i=0; i<g[a].size(); i++)
		if(!used[g[a][i]])
			dfs(g[a][i]);
	myStack.push_back(a);
	return;
}
void back_dfs(int a){
	cout << a+1<<" ";
	used[a]=true;
	for(int i=0; i<bg[a].size(); i++)
		if(!used[bg[a][i]])
			back_dfs(bg[a][i]);
}
void find_comps(){ 
	fill_n(used,n,false);
	comps=0;
	for(int i=0; i<n; i++)
		if(!used[i])
			dfs(i);
	fill_n(used,n,false);
	while(myStack.size()!=0){
		myStack.pop_back(); 
		int v=*(myStack.end()); 
		if(!used[v]){
			cout << ++comps<<": ";
			back_dfs(v);
			cout << endl;
		}
	}
}

int main(){
	cin >> n>>m;
	for(int i=0; i<m; i++){
		int a,b;
		cin >>a>>b;
		g[a-1].push_back(b-1);
		bg[b-1].push_back(a-1);
	}
	find_comps();
	return 0;
}
