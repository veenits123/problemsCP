#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  //int t;cin>>t;while(t--){}
  int a,cube,sum=0,rem;cin>>a;
   while(a>0)
     { rem=a%10;
       cube=rem*rem*rem;
       sum+= cube;
       a/=10;
     }
     cout<<sum<<endl;
    
  
  return 0;
}