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
  	int fb=0,sb=0;
  	int n,k;cin>>n>>k;
  	for(int i=n-2;i>=0;i--){
  		if(k<=n-i-1){
  			fb=i;
  			break;
  		}
  		else{
  			k-=n-i-1;//??
  		}
  	}
  	sb=n-k;

  	string s(n,'a');
  	s[fb]='b';s[sb]='b';
  	
  	cout<<s<<endl;
  }
    
  
  return 0;
}