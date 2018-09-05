#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    stack<int> s;

    //push the first element to the stack
    s.push(ar[0]);
    for(int i=1;i<n;i++)
    {

        //if q is empty that means current element will not be next
        //greater element of any of the previous element just push
        //current element and continue
        if(s.empty())
        {
            s.push(ar[i]);
            continue;
        }

        /*
            if element at top of the stack is less than current element
            than current element will be next greter element for all those elements      */
        while(!s.empty() && s.top() < ar[i])
        {
            printf("Next greter element of %d is %d\n",s.top(),ar[i]);
            s.pop();
        }
        s.push(ar[i]);
    }

    //if stack is not empty that means next greater element does not exist
    //for all those elements
    while(!s.empty())
    {
        printf("Next greater element of %d does not exist\n",s.top());
        s.pop();
    }
    return 0;
}
