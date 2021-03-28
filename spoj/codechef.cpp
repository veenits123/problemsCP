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
  	string s;cin>>s;
  	int n=s.length();
  	string ans="";
  	for(int i=0;i<n;i++){
  		char c=s[i]+n;
  		if (c>='a' and c<='z') ans+=c;
  		else ans+=c-26;
  	}
  	cout<<ans<<endl;
  }

  
  return 0;
}