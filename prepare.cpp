#include <bits/stdc++.h>
using namespace std;
	
	//Return i-th digit of the given number. Usage: Digit(number, index)
	long long Digit (long long a, long long i){return (long long)(a/=pow(10,i-1))%10;}
	
	//Return length of the given number. Usage: Lenght(number)
	long long Length (long long a){long long i=0; while(a){a/=10; i++;} return i;}
	
	//Reverse strings. Usage: Reverse(string)
	string Revese (string s){ string t="";
		for(int i=0; i<s.size(); i++)t+=s[s.size()-1-i]; return t;
	}
	
	//Cut string from p-th index with length of n. Usage: Cut(string, position, length)
	string Cut (string s, long long p, long long n){ string t="";
		for(int i=0; i<n; i++)t+=s[p+i]; return t;
	}
	
	//Return sum of digits tbe gkven string. Usage: Digits_Sum(number)
	long long Digits_Sum (long long a){long long s=0; while(a){s+=a%10; a/10;}}
	
	//Return the number in string form. Usage: Int_To_String(number)
	string Int_To_String (long long x){string t=""; while(x){t+='0'+x%10; x/=10;} return rev(t);}
	
	//Return the string form of a number. Usage: String_To_Int(string)
	long long String_To_Int (string t){ long long s=0;
		for(int i=0; i<t.size(); i++)s+=t[t.size()-1-i]*pow(10,i); return s;
	}
	
	//Return sum of two numbers in string. Usage Sum(string, string)
	string Sum (string a, string b){return its(sti(a)+sti(b));}
	
	//Return true/false if a is/isn't a counter of n. Usage: Is_Counter(string/number, string/number)
	bool Is_Counter (string a, string b){if(String_To_Int(b)%String_To_Int(a)==0)return true; else return false;}
	bool Is_Counter (string a, long long b){if(b%String_To_Int(a)==0)return true; else return false;}
	bool Is_Counter (long long a, string b){if(String_To_Int(b)%a==0)return true; else return false;}
	bool Is_Counter (long long a, long long b){if(b%a==0)return true; else return false;}
	
	int main () {
		
	}
