//Using sum formula


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
         int sum=0;
        for(i=0;i<n-1;i++)
        {
            cin>>v[i];
            sum+=v[i];   //Sum of numbers of array
        }
        int sum2=(n*(n+1))/2;   //Sum of numbers from 1 to n
         cout<<sum2-sum<<endl;  //Answer
     }
    return 0;
}