#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  //int t;cin>>t;while(t--){}
  int n;
  while(1){
  	cin>>n;
  	if(n==0) return 0;
  	ld ans=0;
  	ans=n*n/(2*3.1415926);
  	cout<<fixed<<setprecision(2)<<ans<<endl;
  }
    
  
  return 0;
}