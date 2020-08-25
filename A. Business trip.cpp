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

  int k;cin>>k;
  vector <int> a(12);
  for(int i=0;i<12;i++){
  	cin>>a[i];
  }
  sort(a.begin(), a.end(),greater<int>());
  int ans=0,h=0;
  for(int i=0;i<12;i++){
  	if(h>=k) break;
  	h+=a[i],ans++;
  }
  if(h<k) cout<<-1;
  else cout<<ans;
    
  
  return 0;
}