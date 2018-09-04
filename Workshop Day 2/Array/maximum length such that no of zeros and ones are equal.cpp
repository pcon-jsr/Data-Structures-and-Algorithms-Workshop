#include<bits/stdc++.h>
using namespace std;

//this funtion will return the maximum length of sub array
//that contains equal no of zeros and ones
int maxLen(int ar[],int n)
{

    //take the map which will store the first occurrences of each
    //sum sum in cumulative array if that sum is not zero
    map<int,int> mp;

    //it will take the cumulative sum of all elements of array taking 1 as 1 and 0 as -1
    int cumSum[n+2];
    for(int i=0;i<=n;i++)
        cumSum[i]=0;

    //0 will contribute -1 quantity and 1 will contribute 1 quantity to total sum
    cumSum[1]=(ar[1]==1)?1:-1;

    //taking cumulative sum
    for(int i=2;i<=n;i++)
        cumSum[i]=cumSum[i-1]+((ar[i]==1)?1:-1);
    //now the question becomes finding the maximum length of sub array in which total
    //sum is zero

    //maxLen will store the maximum length
    int mxLen=0;
    for(int i=1;i<=n;i++)
    {

        /*
            if cumulative sum up to this point is zero from the initiation then
            no of zeros and ones are equal in no from the starting of array
        */
        if(cumSum[i]==0)
            mxLen=i;

        /*
            if this cumulative sum is not visited previously then
            store the first index at which this sum occur
        */
        else if(mp[cumSum[i]]==0)
            mp[cumSum[i]]=i;

        /*
            if this sum is previously visited then from that point up to this
            current point i the sum of that sub array has contributed a total of zero value
            as the value remains constant so update the max length accordingly
        */
        else if(mp[cumSum[i]])
            mxLen=max(mxLen,i-mp[cumSum[i]]);
    }

    //return the maximum length
    return mxLen;
}
int main()
{
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    int len=maxLen(ar,n);
    cout<<"Maximum length subarray is:"<<len;
    return 0;
}
