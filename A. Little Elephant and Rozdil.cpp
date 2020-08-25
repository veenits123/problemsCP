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
  int n;cin>>n;
  vector <P> a;
  for(int i=0;i<n;i++){
  	int x;cin>>x;
  	a.pb({x,i+1});
  }
  sort(a.begin(),a.end());

  if(a[0].F==a[1].F) cout<<"Still Rozdil";
  else cout<<a[0].S;
    
  
  return 0;
}