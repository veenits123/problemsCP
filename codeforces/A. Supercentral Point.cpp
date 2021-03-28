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
  int n;cin>>n;
  vector <P> a(n);
  for(int i=0;i<n;i++){
  	cin>>a[i].F>>a[i].S;
  }
  //for(auto x:a) cout<<x.F<<" "<<x.S<<endl;
  int ans=0;
  for(int i=0;i<n;i++){
  	int z=0,b=0,c=0,d=0;
  	for(int j=0;j<n;j++){
  		//cout<<a[i].F<<" "<<a[i].S<<endl;
  		//cout<<a[j].F<<" "<<a[j].S<<endl;
  		if (a[i].F>a[j].F and a[j].S==a[i].S) z|=1;
  		if (a[i].F<a[j].F and a[j].S==a[i].S) b|=1;
  		if (a[j].F==a[i].F and a[i].S>a[j].S) c|=1;
  		if (a[j].F==a[i].F and a[i].S<a[j].S) d|=1;
		
  	}
  	//cout<<c<<endl;
  	if(z & b & c & d) ans++;
 
  }
  cout<<ans;
    
  
  return 0;
}