//Print distinct elements in an array in sorted order using set
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
#define testcase int tc;cin>>tc;while(tc--)
int main()
{
	fastio;
	testcase                       
	{
		int n;
		cin>>n;
		if(n==0)
		{
			cout<<"Invalid\n";
			continue;
		}
		set<int> s;          //Set used instead of unordered_set for sorted order
		vector<int> v(n);    //Try to make the program without using this vector
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			s.insert(v[i]);                //Insertion in set takes O(log n) time
		}
		for(auto it=s.begin();it!=s.end();it++)    // set<int>::iterator it and auto it are equivalent
  		{
			cout<<*it<<" ";                      //Traverse the set using iterator and print values
		}
		cout<<"\n";
	}
}


/*
Further Taks;
1.Try to make a set which stores values in descending order.
If the ans was (1,2,3) it should be (3,2,1) now.
2.Try to traverse the set in opposite order
If the ans was (1,2,3) it should be (3,2,1) now but use the set<int> s itself.
*/