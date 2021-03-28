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

  int t;cin>>t;cout<<endl;while(t--){
  	//cout<<endl;
  	int n,res=0;cin>>n;
  	for(int i=0;i<n;i++){
  		int x;cin>>x;
  		res=(res+x)%n;
  	}
  	if (res%n==0) cout<<"YES"<<endl;
  	else cout<<"NO"<<endl;
  }
    
  
  return 0;
}