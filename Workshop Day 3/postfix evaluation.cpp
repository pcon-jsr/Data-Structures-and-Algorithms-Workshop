#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int i=0;
    stack<char> v;
    while(i<n)
    {
        if(s[i]!='/' && s[i]!='*' && s[i]!='+' && s[i]!='-')
        {
            v.push(s[i]);
            i++;
        }
        else
        {
            int p=v.top()-'0';
            v.pop();
            //cout<<"P="<<p<<" Q=";
            int q=v.top()-'0';v.pop();
            if(s[i]=='*')
                q*=p;
            else if(s[i]=='/')
                q/=p;
            else if(s[i]=='+')
                q+=p;
            else if(s[i]=='-')
                q-=p;
            //cout<<q<<endl;
            v.push(q+'0');
            i++;

        }
    }
    cout<<v.top()-'0'<<endl;
    return 0;
}
