#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int dp[5001];

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  //int t;cin>>t;while(t--){
  string s;cin>>s;
  while(s[0]!='0'){
  if (s[0]=='0') break;
  dp[0]=dp[1]=1;
  int n=s.length();
  for(int i=2;i<=n;i++){
  	dp[i]=0;
  	//if (s[i]-'0') dp[i]=dp[i-1]; 
  	if ((((s[i-2]-'0')*10+(s[i-1]-'0'))>=10 and ((s[i-2]-'0')*10+(s[i-1]-'0'))<=26) or s[i-2]-'0'==1){
  		dp[i]+=dp[i-2];
  	}
  	if (s[i-1]-'0'!=0){
  		dp[i]+=dp[i-1];
  	}
  }
  cout<<dp[n]<<endl;
  cin>>s;
}
    
  
  return 0;
}