#include<bits/stdc++.h>
using namespace std;
void heapify(int ar[],int n,int i)
{
    int l=2*i+1,r=2*i+2,smallest=i;
    if(l<n && ar[l]<ar[i])
        smallest=l;
    if(r<n && ar[r]<ar[smallest])
        smallest=r;
    if(i!=smallest)
    {
        swap(ar[i],ar[smallest]);
        heapify(ar,n,smallest);
    }
}
void buildheap(int ar[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(ar,n,i);
}
int extract(int ar[],int *size)
{
    if(*size<=0)
        return INT_MAX;
    int root=ar[0];
    ar[0]=ar[*size-1];
    (*size)--;
    heapify(ar,*size,0);
    return root;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int ar[n+3];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int mn[k+3];
    for(int i=0;i<=k;i++)
        mn[i]=ar[i];
    buildheap(mn,k+1);
    int p=k+1;
    for(int i=k+1,c=0;c<n;c++,i++)
    {
        if(i<n)
        {
            ar[c]=mn[0];
            mn[0]=ar[i];
            heapify(mn,k+1,0);
        }
        else
            ar[c]=extract(mn,&p);
    }
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
    return 0;
}
