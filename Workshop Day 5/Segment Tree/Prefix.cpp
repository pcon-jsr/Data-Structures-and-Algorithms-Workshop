/*
Program for Computation of Range Sum with Prefix sum and no updates
Sample input
5
2 1 4 3 4
3
1 2
0 3
3 4
Sample Output
5
10
7
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;         //Size of Array
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	int q;
	cin>>q;
	int l,r;
	/*--------Prefix Sum PreComputation---------*/
	vector<int> pref(n,0);
	pref[0]=a[0];
	for(int i=1;i<n;i++)
	{
		pref[i]=a[i]+pref[i-1];
	}
	//Handle the queries in O(1)
	while(q--)
	{
		cin>>l>>r;
		if(l==0)
		{
			cout<<pref[r]<<"\n";
		}
		else
		{
			cout<<pref[r]-pref[l-1]<<"\n";
		}
	}
	return 0;
}