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

  //int t;cin>>t;while(t--){
  int n;cin>>n;
  int cnt=0;
  for(int i=1;i<=sqrt(n);i++){
  	for(int j=i+1;i*j<=n;j++){
  		cnt++;
  	}
  }
  cnt+=sqrt(n);
  cout<<cnt;

    
  
  return 0;
}