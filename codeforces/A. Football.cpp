#include <bits/stdc++.h>
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
  int n;cin>>n;
  string s;
  map <string,int> m;
  while(n--){
  	cin>>s;
  	m[s]++;
  }
  map <int,string,greater<int> > mp;
  for(auto x:m) mp.insert({x.S,x.F});
  cout<<mp.begin()->S;
    
  
  return 0;
}