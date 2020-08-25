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
  vector <int> a(n+1);
  vector <P> c(n+1);
  for(int i=1;i<=n;i++){
  	c.pb({0,0});
  }
  //for(int i=1;i<=n;i++) cout<<c[i].F<<" "<<c[i].S<<endl;
  for(int i=1;i<=n;i++){
  	cin>>a[i];
  	c[a[i]].F=i;
  	c[a[i]].S=n-(i-1);
  }
  int m;cin>>m;
  int vats=0,pets=0;
  while(m--){
  	int key;cin>>key;
  	vats+=c[key].F;
  	pets+=c[key].S;
  }
  cout<<vats<<" "<<pets;
    
  
  return 0;
}