#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
int main()
{
        string s;
        cin>>s;
        int n=s.size();
        stack<char> s1;
        string o="";
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a'&& s[i]<='z' || s[i]>='A' && s[i]<='Z')
                o+=s[i];
            else if(s[i]=='(')
                s1.push(s[i]);
            else if(s[i]==')')
            {
                while(!s1.empty() && s1.top()!='(')
                {
                    o+=s1.top();
                    s1.pop();
                }
                s1.pop();
            }
            else
            {
                while(!s1.empty() && prec(s[i])<=prec(s1.top()))
                {
                    o+=s1.top();
                    s1.pop();
                }
                s1.push(s[i]);
            }
        }
        while(!s1.empty())
        {
            o+=s1.top();
            s1.pop();
        }
        cout<<o<<endl;
    return 0;
}
