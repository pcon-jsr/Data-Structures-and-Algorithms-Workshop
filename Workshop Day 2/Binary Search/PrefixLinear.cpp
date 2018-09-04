#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
int main()
{
    int i,n;
    cin>>n;
    vector<int> v(n);
    for(i = 0 ; i < n ; i++)
    { 
        cin>>v[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int ts=0;
        for(i = 0 ; i < n ; i++)
        {
            ts+=v[i];
            if(ts>=s)
            {
                cout<<i<<"\n";
                break;
            }
        }
        if(i==n)cout<<-1<<"\n";
    }
    return 0;
}