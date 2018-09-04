#include<bits/stdc++.h>
using namespace std;

//this function will print the intersection of two array
void findIntersection(int ar1[],int ar2[],int n1,int n2)
{

    //take an unordered map to store the count of each array element
    unordered_map<int,int> mp;
    for(int i=0;i<n1;i++)
        mp[ar1[i]]++;

    /*
        now traversing the second array,
        if the number of count in map of current element is >0
        that means this element is also present in first array
        print it and reduce the count of corresponding element by 1
        and propagate further
    */
    for(int i=0;i<n2;i++)
    {
        if(mp[ar2[i]]!=0)
        {
            cout<<ar2[i]<<" ";
            mp[ar2[i]]--;
        }
    }
}

int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int ar1[n1+2],ar2[n2+2];
    for(int i=0;i<n1;i++)
        cin>>ar1[i];
    for(int i=0;i<n2;i++)
        cin>>ar2[i];
    findIntersection(ar1,ar2,n1,n2);
    return 0;
}

