/*
	Reference Problem-https://www.spoj.com/problems/HORRIBLE/
	Segment tree with lazy propagation
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v;
vector<ll> seg;
vector<ll> lazy;
void build(int pos,int start,int end)
{
  if(start==end)
  {
    seg[pos]=v[start];
  }
  else
  {
    int mid=(start+end)>>1;
    build(2*pos+1,start,mid);
    build(2*pos+2,mid+1,end);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
  }
}
/*---updateRange using lazy propagation---*/
void updateRange(int pos,int start,int end,ll l,ll r,ll val)
{
  if(lazy[pos]!=0)
  { 
    seg[pos] += (end - start + 1) * lazy[pos];
    if(start != end)
    {
      lazy[(pos<<1)+1] += lazy[pos];
      lazy[(pos<<1)+2] += lazy[pos];
    }
    lazy[pos] = 0;                         
  }
  if(start > end || start > r || end < l)return;
  if(start >= l and end <= r)
  {
    seg[pos] += (end - start + 1) * val;
    if(start != end)
    {
      lazy[(pos<<1)+1] += val;
      lazy[(pos<<1)+2] += val;
    }
    return;
  }
  int mid = (start + end)>>1;
  updateRange((pos<<1)+1, start, mid, l, r, val);        
  updateRange((pos<<1)+2, mid + 1, end, l, r, val);  
  seg[pos] = seg[(pos<<1)+1] + seg[(pos<<1)+2];
}
/*---Query for Value---*/
ll query(int pos, int start, int end, int l, int r)
{
  if(start > end or start > r or end < l)
        return 0;      
    if(lazy[pos]!=0)
    {
        seg[pos]+=(end-start+1)*lazy[pos];          
        if(start != end)
        {
            lazy[(pos<<1)+1] += lazy[pos];    
            lazy[(pos<<1)+2] += lazy[pos];    
        }
        lazy[pos] = 0;        
    }
    if(start >= l and end <= r)
        return seg[pos];
    ll mid = (start + end)>>1;
    return (query((pos<<1)+1, start, mid, l, r)+query((pos<<1)+2, mid + 1, end, l, r));
}
int main()
{
  int tc;
  cin>>tc;
  while(tc--)
  {
    int n,q;
    cin>>n>>q;
    ll l,r,val;
    v.resize(n,0);
    seg.resize(2e6+5,0);
    lazy.resize(2e6+5,0);
    build(0,0,n-1);
    for(int i=0;i<q;i++)
    {
      short qt;
      cin>>qt;
      if(qt==0)
      {
          cin>>l>>r>>val;
          updateRange(0,0,n-1,l-1,r-1,val);
      }
      else
      {
        cin>>l>>r;
        cout<<query(0,0,n-1,l-1,r-1)<<endl;
      }
    }
    seg.clear();
    v.clear();
    lazy.clear();
  } 
  return 0;
}