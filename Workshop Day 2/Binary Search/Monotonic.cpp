#include <bits/stdc++.h>
using namespace std;
#define faster cin.tie(0);ios_base::sync_with_stdio(0)
#define testcase int tc;cin>>tc;while(tc--)

//Function to calculate f(x)
ll val(ll a,ll b,ll c,ll x)
{
    return ((a*x*x)+(b*x)+c);
}
//Binary Search Function
ll bs(ll a,ll b,ll c,ll k)
{
    if(val(a,b,c,0)>=k)return 0;
    ll low=1;
    ll high=100000;
    while(low<high)
    {
        ll mid=(low+high)>>1;
        if(val(a,b,c,mid)<k)
        {
            low=mid+1;
        }
        else if(val(a,b,c,mid)>=k) 
        {
            high=mid;
        }
    }
    return low;
}

int main()
{
    faster;
    testcase
    {
        ll a,b,c,k;
        cin>>a>>b>>c>>k;
        cout<<bs(a,b,c,k)<<"\n";
    }
    return 0;
}