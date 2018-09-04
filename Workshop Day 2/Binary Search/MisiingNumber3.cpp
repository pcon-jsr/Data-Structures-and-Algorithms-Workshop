//Using XOR

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
        int x1=0;
        vi v(n-1);
        for(i=0;i<n-1;i++)
        {
            cin>>v[i];
            x1=x1^v[i];   //Xor of the input numbers
        }
        for(i=1;i<=n;i++)
        {
            x1=x1^i;   //Xor with numbers from 1 to n
        }
        cout<<x1<<endl;
    }
}