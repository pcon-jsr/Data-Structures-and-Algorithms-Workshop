//Using binary search

//Find missing number in an array of the form 1 to n
/*
Sample Input 1
4 
0 1 2 3 
Sample Output 1
4

Sample Input 2
4 
0 1 2 4
3
*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
#define testcase int tc;cin>>tc;while(tc--)
typedef vector<int> vi;
int findFirstMissing(vi &array,int start,int end)
{
    if (start  > end)
        return end + 1;
    if (start != array[start])
        return start;
    int mid = (start + end) / 2;
    // Left half has all elements from 0 to mid
    if (array[mid] == mid)
        return findFirstMissing(array, mid+1, end);
    return findFirstMissing(array, start, mid);
}
int main()
{
    testcase
    {
        int n;
        cin>>n;
        vi v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        cout<<findFirstMissing(v,0,n-1)<<endl;
    }
    return 0;
}