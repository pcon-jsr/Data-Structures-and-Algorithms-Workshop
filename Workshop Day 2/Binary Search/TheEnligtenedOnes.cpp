#include <bits/stdc++.h>
using namespace std;
#define faster cin.tie(0);ios_base::sync_with_stdio(0)
#define testcase int tc;cin>>tc;while(tc--)
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
const ll mod=1000000007;
#define all(x) x.begin(),x.end()
#define allR(x) x.rbegin(),x.rend()
/*----------------------------*/
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
/*---------------------------*/
bool check(ll mid,ll k,vector<ll> &v)
{
    ll fi=v[0]+mid;
    k--;
    ll n=v.size();
    for(ll i=1;i<n;i++)
    {
        if(fi+mid>=v[i])continue;
        if(k==0)return true;
        fi=v[i]+mid;
        k--;
    }
    return false;
}
int main()
{
    faster;
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)cin>>v[i];
    sort(all(v));
    ll low=0,high=1e9;
    while(low<=high)
    {
        ll mid=(low+high)>>1;
        if(check(mid,k,v))
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<low<<endl;
    return 0;
}
