#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int q;

    //no of queries 10^5
    cin>>q;
    while(q--)
    {

        //left range, right range and value to be summed in given range
        int l,r,val;
        cin>>l>>r>>val;

        //l should be less than number of elements in array
        if(l>n)
            continue;
        //Generally, we would add the values to all the elements in the given range
        //but here we just mark the range that's given in the query

        //Add value to the first element of given range so that in taking cumulative sum after all queries
        //the val quantity should be propagate from L to R
        ar[l]+=val;

        //after range ends,i.e., after r the value(val) should not be propagated any further
        if(r+1<n)
            ar[r+1]+=-val;
    }

    //now after every query, take the cumulative sum, it will update all elements of array properly
    for(int i=1;i<n;i++)
    {
        ar[i]+=ar[i-1];
    }
    int q1;
    cin>>q1;
    while(q1--)
    {
        int index;
        cin>>index;
        cout<<ar[index]<<endl;
    }
    return 0;
}
