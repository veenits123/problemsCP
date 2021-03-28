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

  int t;cin>>t;while(t--){
    int n,m;cin>>n>>m;
    vector <int> f(n),p(n);
    map <int,int> mp;
    map <int,int> res;
    for(int i=0;i<n;i++){
      cin>>f[i];
    }
    for(int i=0;i<n;i++){
      cin>>p[i];
    }
    for(int i=0;i<n;i++){
      mp[f[i]]+=p[i];
    }
    for(auto x:mp){
      res.insert({x.S,x.F});
    }
    for(auto x:res){
      cout<<x.F<<endl;
      break;
    }
  }
    
  
  return 0;
}