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
  int n;cin>>n;
  set <int> s;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      s.insert(i);
      n=n/i;
      break;
    }
  }
   for(int i=2;i*i<=n;i++){
    if(n%i==0 and s.count(i)==0){
      s.insert(i);
      n=n/i;
      break;
    }
  }
  if(s.size()<2 or n==1 or s.count(n)){
    cout<<"NO"<<endl;
  }
  else{
    s.insert(n);
    cout<<"YES"<<endl;
    for(auto x:s){
      cout<<x<<" ";
    }
    cout<<endl;
  }
}
 
  return 0;
}