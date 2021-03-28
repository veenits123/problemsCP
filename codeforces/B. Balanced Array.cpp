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

  int t;cin>>t;while(t--){

  	int n;cin>>n;
  	if(n/2&1) cout<<"NO"<<endl;
  	else{
  		cout<<"YES"<<endl;
  		for(int i=1;i<=n/2;i++){
  			cout<<2*i<<" ";
  		}
  		for(int i=1;i<n/2;i++){
  			cout<<2*i-1<<" ";
  		}
  		cout<<n+n/2-1<<" ";
  		cout<<endl;

  	}


  }
    
  
  return 0;
}