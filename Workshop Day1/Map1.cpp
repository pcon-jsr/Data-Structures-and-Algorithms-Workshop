//Print the attendance of students attending the workshop
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
#define testcase int tc;cin>>tc;while(tc--)
int main()
{
	fastio;
	int n;
	cin>>n;
	string s;     //To input roll no.
	map<string,int> m;   //Key value "pair" in a map
	while(n--)
	{
		cin>>s;
		m[s]++;     //Increment the attendance
	}
	for(auto it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<" "<<it->second<<"\n";    //Why did we use first and second here??
	}
}


/*
Further tasks
Write a program that answers queries of the following type-
	1.Mark the attendance of the student
	2.Delete the student entry
	3.Decrement the attendance of the student
	4.How many days was the student present

Sample Input 
11
1 2017UGMM012
1 2017UGMM012
2 2017UGMM001
3 2017UGMM012
4 2017UGMM012	
1 2017UGMM012
1 2017UGMM011
1 2017UGMM012
1 2017UGMM011
4 2017UGMM011
4 2017UGMM012

Sample Output
1
2
3
*/