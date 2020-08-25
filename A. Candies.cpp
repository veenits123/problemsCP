#include <iostream>
#include <cmath>
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
  	int ans=1;
  	for(int i=1;i<n;i++){
  		ans += pow(2,i);
  		//cout<<ans<<endl;
  		if(n%ans==0){
  			break;
  		}
  	}
  	cout<<n/ans<<endl;

  }
    
  
  return 0;
}