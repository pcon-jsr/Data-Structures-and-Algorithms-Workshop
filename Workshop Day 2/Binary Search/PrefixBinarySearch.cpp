/*
Sample Input
5
2 1 3 4 8
4
1
3
4
99
Sample Output
0
1
2
-1
*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
int main()
{
    int i,n,s;
    cin>>n;
    vector<int> v(n);
    for(i = 0 ; i < n ; i++)
    { 
        cin>>v[i];
    }
    vector<int> pref(n,0);
    pref[0]=v[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+v[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        cin>>s;
        auto it=lower_bound(pref.begin(),pref.end(),s);
        int ans=distance(pref.begin(),it);
        if(ans==n)cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }
    return 0;
}