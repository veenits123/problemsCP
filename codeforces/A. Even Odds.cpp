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
  int n,k;cin>>n>>k;
  int mid=(n+1)/2;
  //cout<<mid<<endl;
  if(mid>=k) cout<<2*k-1;
  else{
  	k-=mid;
  	cout<<2*k;
  }
  
  return 0;
}