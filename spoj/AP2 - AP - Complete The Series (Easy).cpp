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
  	int af3,al3,sum;cin>>af3>>al3>>sum;
  	int n=(2*sum)/(af3+al3);
  	int d=(al3-af3)/(n-5);
  	int a=af3-2*d;
  	int i=0;
  	cout<<n<<endl;
  	while(i<n){
  		cout<<a+(i*d)<<" ";
  		i++;
  	}
  	cout<<endl;
  }
    
  
  return 0;
}