#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    if(n==1)
    return 0;
    
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        for(int i=a;i<=b;i++)
        {
            if(isprime(i))
            {
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}