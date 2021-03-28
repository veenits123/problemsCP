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

  int t;cin>>t;while(t--){
  	string s;cin>>s;
  	vector <int> a;
  	a.pb(0);
  	for(int i=0;i<s.size();i++){
  		if(s[i]=='R'){
  			a.pb(i+1);
  		}
  	}
  	a.pb(s.size()+1);
  	//for(auto x:a) cout<<x<<" ";cout<<endl;
  	int ans=0;
  	for(int i=0;i<a.size()-1;i++){
  		if((a[i+1]-a[i])>ans){
  			ans=a[i+1]-a[i];
  		}
  	}
  	cout<<ans<<endl;
  }
    
  
  return 0;
}
