#include <iostream>
using namespace std;
int hanoi(int n,char s,char t,char f)
{
	if(n==1) cout<<s<<" --> "<<f<<endl;
	else
	{
		hanoi(n-1,s,f,t);
		cout<<s<<" --> "<<f<<endl;
		hanoi(n-1,t,s,f);
	}
}
int main()
{
	int n;
	cout<<"please insert DiscNum start - temp - finish"<<endl;
	char s,t,f;
	cin>>n>>s>>t>>f;
	hanoi(n,s,t,f);
}
