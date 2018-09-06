//max heap implementation
#include<bits/stdc++.h>
using namespace std;

void heapify(int ar[],int n,int i)
{
    int l=2*i+1,r=2*i+2;
    int largest=i;
    if(l<n && ar[l]>ar[i])
        largest=l;
    if(r<n && ar[r]>ar[largest])
        largest=r;
    if(i!=largest)
    {
        swap(ar[i],ar[largest]);
        heapify(ar,n,largest);
    }
}
void buildHeap(int ar[],int n)
{
    for(int i=(n-1)/2;i>=0;i--)
        heapify(ar,n,i);
}
int main()
{
    int n;
    cin>>n;
    int ar[n+3];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    buildHeap(ar,n);
    cout<<"Array element after heap construction:\n";
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    return 0;
}

