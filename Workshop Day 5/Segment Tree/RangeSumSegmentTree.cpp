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
#define MAX 1000000
#define ll long long int
ll seg[2*MAX-1];
ll in[MAX];
void construct_tree(int low,int high,int pos)
{
    if(low==high)                //Reached leaf node
	{
        seg[pos]=in[low];
        return;
    }
    int mid=(low+high)/2;
    construct_tree(low,mid,2*pos+1);              //recursively go to the left subtree
    construct_tree(mid+1,high,2*pos+2);           //recursively go to the right subtree    
    seg[pos]=(seg[2*pos+1]+seg[2*pos+2]);         //Update the value
}
int query(int low,int high,int l,int r,int pos)
{
    if(r<low || l>high)           //If current range is not considerable
		 return INT_MAX;
    if(l<=low&&r>=high)     //If current range is the required range
		return seg[pos];
    int mid=(low+high)/2;
    return (query(low,mid,l,r,2*pos+1) + query(mid+1,high,l,r,2*pos+2));      //Return the result
}
int main()
{
    int l,r,n,q;
    cin>>n;
    for(int i=0;i<n;i++)cin>>in[i];
	cin>>q;
    construct_tree(0,n-1,0);            //Build the segment tree
    while(q--)
	{
        cin>>l>>r;
		int sum=query(0,n-1,l,r,0);    //Query the segment tree
		cout<<sum<<endl;
    }
    return 0;
}