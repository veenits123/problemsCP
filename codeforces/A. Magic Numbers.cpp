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
  bool flag=true;
  if(s[0]!='1') flag=false;
  set <char> st;

  for(int i=0;i<s.size();i++){
  	st.insert(s[i]);
  	if(s[i]!='1' and s[i]!='4'){
  		flag=false;
  	}

  	if(s[i]=='4' && s[i+1]=='4' && s[i+2]=='4') flag=false;
  }
  if(st.size()>2) flag=false;
 
  if(flag) cout<<"YES";
  else cout<<"NO";
    
  
  return 0;
}