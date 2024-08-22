//Suffix modulo calculation is done here imp
// https://codeforces.com/problemset/problem/490/C link
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
using namespace std;
typedef long long ll;
string s;
ll a[1000005];
ll A,B;
int main()
{
	int t,i,j,k;
	cin>>s>>A>>B;
	ll t1=1,t2,t3;
	for(i=s.size()-1;i>=0;i--)
	{
		a[i]=t1*(s[i]-'0')+a[i+1];
		a[i]%=B;
		t1*=10;
		t1%=B;
	}
	t1=0;
	for(i=0;i<s.size()-1;i++)
	{
		t1=t1*10+s[i]-'0';
		t1%=A;
		if(s[i+1]!='0')
		{
			if((t1==0)&&(a[i+1]==0))
			{
				cout<<"YES\n";
				for(j=0;j<=i;j++)cout<<s[j];
				cout<<endl;
				for(j=i+1;j<s.size();j++)cout<<s[j];
				cout<<endl;return 0;
			}
		}
	}
	cout<<"NO\n";
	return 0;
}
