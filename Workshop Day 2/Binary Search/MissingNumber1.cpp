//Using linear search

//Find missing number in an array of the form 1 to n
/*
Sample Input
5
1 2 3 5
Sample Output 
4
*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
#define testcase int tc;cin>>tc;while(tc--)
typedef vector<int> vi;
int main()
{
    testcase
    {
        int i,n;
        cin>>n;
        vi v(n-1);
        for(i=0;i<n-1;i++)
        {
            cin>>v[i];
        }
        for(i=0;i<n-1;i++)
        {
            if(i+1!=v[i])
            {
                cout<<i+1<<endl;
                break;
            }
        }
        if(i==n-1)
        {
            cout<<n<<endl;
        }
    }
    return 0;
}