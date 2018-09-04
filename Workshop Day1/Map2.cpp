#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
#define testcase int tc;cin>>tc;while(tc--)
int main()
{
	fastio;
	int q;
	cin>>q;
	string s;     //To input roll no.
	map<string,int> m;   //Key value "pair" in a map
	while(q--)
	{
		int t;
		cin>>t;
		cin>>s;
		if(t==1)
		{
			m[s]++;
		}
		else if(t==2)
		{
			m.erase(s); //erase by value,key not found but no error generated
		}
		else if(t==3)
		{
			if(m.find(s)!=m.end())
				m[s]--;
		}
		else
		{
			cout<<m[s]<<"\n";   //If key is not present,what will be the output?
		}
	}
}
