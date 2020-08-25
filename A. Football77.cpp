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
  string s;cin>>s;
  bool flag=false;
  int n=s.size();
  int c=0;
  for(int i=0;i<n;i++){
  	char x=s[i];
  	c=0;
  	for(int j=i+1;j<n;j++){
  		if(s[j]!=x) break;
  		if(s[j]==x){
  			c++;
  		}
  		if(c>=6){
  			flag=true;
  			break;
  		}
  	}
  	if(flag) break;
  }
  if(flag) cout<<"YES";
  else cout<<"NO";
    
  
  return 0;
}