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
  	string s;
  	for(int i=0;i<9;i++){
  		cin>>s;
  		for(int i=0;i<9;i++){
  			if(s[i]=='2'){
  				s[i]='1';
  			}
  		}
  		cout<<s<<endl;

  	}
  	cout<<endl;

  }
    
  
  return 0;
}