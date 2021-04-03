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
  int n,m;cin>>n>>m;
  map <int,int> won;
  for(int i=1;i<=n;i++){
  	won[i]=0;
  }
  while(m--){
  	int a,b,c;cin>>a>>b>>c;
  	if(c==a) won[b]=c;
  	if(c==b) won[a]=c;
  }
  for(auto x:won) cout<<x.S<<" ";
    
  
  return 0;
}