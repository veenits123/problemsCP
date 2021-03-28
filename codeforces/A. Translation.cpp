#include <iostream>
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
  string s,t;cin>>s>>t;
  int n=s.size();
  string ans="YES";
  for(int i=0;i<n;i++){
  	if(s[i]!=t[n-i-1]){
  		ans="NO";
  		break;
  	}
  }
  cout<<ans;
    
  
  return 0;
}