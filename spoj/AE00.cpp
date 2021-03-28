#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int power(int a,int b,int n){
	int res=1;
	a=a%n;
	while(b>0){
		if (b&1) res=res*a%n;

		a=a*a%n;
		b>>=1;
	}
	return res;
}

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  int t;cin>>t;while(t--){
  	int a,b;cin>>a>>b;
  	cout<<power(a,b,10)%10<<endl;

  }

    
  
  return 0;
}
