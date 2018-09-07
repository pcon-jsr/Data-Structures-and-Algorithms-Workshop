//Range min queries with updates
/*
Sample Input
5
1 9 3 4 2
6
1 1 3
1 0 4
2 1 0
1 0 4
2 0 -2
1 0 2
Sample Output
3
1
0
-2
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
#define ll long long int
/*----------*/
template <typename T>
T Max(T a,T b)
{
    return a>b?a:b;
}
template <typename T>
T Min(T a,T b)
{
    return a<b?a:b;
}
/*-----*/
vector<ll> seg(2*MAX+2,0);
vector<ll> in(MAX);
void construct_tree(int low,int high,int pos)
{
    if(low==high)
	{
        seg[pos]=in[low];
        return;
    }
    int mid=(low+high)/2;
    construct_tree(low,mid,2*pos+1);
    construct_tree(mid+1,high,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
void update_tree(int low,int high,int val,int idx,int pos)
{
    if(low==high)
	{
        in[idx]=val;
        seg[pos]=val;
    }
    else
	{
	    int mid=(low+high)/2;
	    if(low<=idx&&idx<=mid)
		{
	        update_tree(low,mid,val,idx,2*pos+1);
	    }
	    else
		{
	      	update_tree(mid+1,high,val,idx,2*pos+2);  
	    }
	    seg[pos]=Min(seg[2*pos+1],seg[2*pos+2]);
    }
}
int query(int low,int high,int l,int r,int pos)
{
    if(r<low or l>high)
	 return INT_MAX;
    if(l<=low and r>=high)
		return seg[pos];
    int mid=(low+high)/2;
    return Min(query(low,mid,l,r,2*pos+1),query(mid+1,high,l,r,2*pos+2));
}
int main()
{
    int l,r,x,y,n,q,t;
    cin>>n;
    for(int i=0;i<n;i++)cin>>in[i];
    construct_tree(0,n-1,0);
    cin>>q;
    while(q--)
	{
        cin>>t;
        if(t==1)
		{
            cin>>l>>r;
            cout<<query(0,n-1,l,r,0)<<endl;
        }
        else
		{
            cin>>x>>y;
            update_tree(0,n-1,y,x,0);
        }
    }
    return 0;
}