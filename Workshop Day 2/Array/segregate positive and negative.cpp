#include<bits/stdc++.h>
using namespace std;

//this function will segregate negattive in left side and positive in right side
void segregate(int ar[],int n)
{

    //initialize i to the left of array and j to the right of array
    int i=0,j=n-1;
    while(i<j)
    {

        //if left side element is already negative then they are already in correct position no need to further swap
        //traverse the array until elements in left side are in their correct position
        while(ar[i]<0)
            i++;

        //if right side element is positive then they are already in their correct position no need to swap
        //traverse the array until elements in right side are in their correct position
        while(ar[j]>=0)
            j--;

        //if elements are out of order then swap them
        swap(ar[i],ar[j]);
        i++;
        j--;
    }
}
int main()
{
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    segregate(ar,n);
    cout<<"Array after segregation\n";
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    return 0;
}
