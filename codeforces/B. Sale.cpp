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
  vector <int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  sort(a.begin(),a.end());
	
  int ans=0;
  for(int i=0;i<m;i++){
  	if(a[i]<0){
  		ans += (-1)*(a[i]);
  	}
  }
  cout<<ans;

    
  
  return 0;
}