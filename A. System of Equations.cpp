#include <iostream>
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
  int n,m;cin>>n>>m;
  int ans=0;
  for(int i=0;i<32;i++){
  	for(int j=0;j<32;j++){
  		if(i*i+j==n && j*j+i==m) ans++;
  	}
  }
  cout<<ans;
    
  
  return 0;
}