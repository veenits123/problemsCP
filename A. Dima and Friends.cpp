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
  vector <int> a(n);
  int sum=0;
  for(int i=0;i<n;i++){
  	cin>>a[i];
  	sum+=a[i];
  }
  int i=1,ans=0;
  while(i<=5){
  	if((sum+i)%(n+1)!=1){
  		ans++;
  	}
  	i++;
  }
  cout<<ans;
  
  return 0;
}