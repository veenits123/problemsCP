#include <iostream>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve(){
	int n,a,b;cin>>n>>a>>b;
	int c=0;
	for(int i=1;i<=n;i++){
		if(a<=i-1 && b>=n-i)
			c++;
	}
	cout<<c<<endl;
}

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  //int t;cin>>t;while(t--)
  solve();
   
  return 0;
}