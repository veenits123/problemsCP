
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
  	int x,y,res=0;cin>>x>>y;
  	if (x==y){
  		if (x&1 and y&1) res=2*x-1;
  		else res=2*x;
  		cout<<res<<endl;
  	}
  	else if (x==y+2) {if (x&1) res=x+y-1;
  				else res=x+y;
  				cout<<res<<endl;}
  	else cout<<"No Number"<<endl;

  }
    
  
  return 0;
}