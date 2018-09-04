#include<bits/stdc++.h>
using namespace std;
int kaden(int ar[],int n)
{
    int max_so_far=0,max_ending_here=0;
    for(int i=0;i<n;i++)
    {
        max_ending_here = max_ending_here + ar[i];
       if (max_ending_here < 0)
           max_ending_here = 0;
       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
    }
    return max_so_far;
}
int main()
{
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int mxSum=kaden(ar,n);
    return 0;
}
