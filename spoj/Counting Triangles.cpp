#include<iostream>
using namespace std;

#define int long long int

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  int t;cin>>t;while(t--){
  	int n;cin>>n;
  	int ans=(n*(n+2)*(2*n+1))/8;
  	cout<<ans<<'\n';
  }
    
  
  return 0;
}