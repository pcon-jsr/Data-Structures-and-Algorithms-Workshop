/*
Program for Computation of Range Sum Brute Force and no updates
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
	//Handle query without precomputation
	while(q--)
	{
		cin>>l>>r;
		int sum=0;
		for(int i=l;i<=r;i++)
		{
			sum+=v[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}