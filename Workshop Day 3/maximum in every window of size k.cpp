#include<bits/stdc++.h>
using namespace std;

//this funtion will print maximum element in every sub array of size k
void printKMax(int ar[],int n,int k)
{

    //taking a dequeue of size k
    deque<int> q(k);
    int i;

    /*
        process 1st k element in dequeue.We will push only those elements
        which are useful.
        Here useful elements means it should be greater than current array
        element and it should be in given sub array range.
        We will make dequeue in such a way that dequeue will be sorted in
        descending order and new element is inserted at back side.
        That means front of dequeue will always contain the maximum element of
        that sub array and front of dequeue will be oldest element.

    */
    for(i=0;i<k;i++)
    {

        //pop out those elements which are not useful
        while(!q.empty() && ar[i]>ar[q.back()])
            q.pop_back();

        //push current element to the back of dequeue
        q.push_back(i);
    }
    for(;i<n;i++)
    {

        //print the maximum element of current window
        cout<<ar[q.front()]<<" ";

        //pop out those elements which are out of range
        while(!q.empty() && q.front()<=i-k)
            q.pop_front();

        //pop out those elements which are not useful
        while(!q.empty() && ar[i]>ar[q.back()])
            q.pop_back();

        //push current element to the back of dequeue
        q.push_back(i);
    }
    cout<<ar[q.front()]<<"\n";
}
int main()
{
    int n,k;
    cin>>n>>k;
    int ar[n+2];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    printKMax(ar,n,k);
    return 0;
}
