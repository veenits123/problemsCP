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
  vector <int> a(n),b(n);
  for(int i=0;i<n;i++){
  	cin>>a[i];
  }
  for(int i=0;i<n;i++){
  	cin>>b[i];
  }
  vector <int> c(n);
  for(int i=0;i<n;i++){
  	c[i]=b[i]-a[i];
  }
  sort(c.begin(),c.end());
  int ans=0;
  for(int i=0;i<n;i++){
  	auto it=lower_bound(c.begin()+i+1,c.end(),-c[i]);
  	auto j=it-c.begin();
  	ans+=j-(i+1);
  }
  cout<<ans;

    
  
  return 0;
}