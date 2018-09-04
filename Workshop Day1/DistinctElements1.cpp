//Find no of distinct elements in an array using set
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)  //FastInputoutput
#define testcase int tc;cin>>tc;while(tc--)   //Testcases
typedef vector<int> vi;
int main()
{
	fastio;
	testcase
	{
		int n;
		cin>>n;
		if(n==0)
		{
			cout<<0<<endl;     
			continue;
		}
		unordered_set<int> s;
		vi v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			s.insert(v[i]);   //Insertion in O(1) time 
		}
		cout<<s.size()<<endl;   //Print the size of the set 
	}
}