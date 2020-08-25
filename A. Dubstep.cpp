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
  string s;cin>>s;
  int n=s.size();
  string ans="";
  int i=0,cnt=0;
  for(i=0;i<n;i++){
  	if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){
  		if(i!=n-1 && cnt && i){
  			ans+=' ';
  		}
  		cnt=0;
  		i+=2;
  	}
  	else{
  		ans+=s[i];
  		cnt=1;
  	}
  }
  cout<<ans;
    
  
  return 0;
}