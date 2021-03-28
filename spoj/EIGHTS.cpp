#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int power(int a,int b){
	int res=1;
	//a%=n;
	while(b>0){
		if (b&1){
			res=res*a;
		}
		a=a*a;
		b>>=1;
	}
	return res;
}

int sum(int n){
	int ans=0,c=0,res=0;
	while(n>0){
		ans=n%10;
		res+=ans;
		
		n/=10;
		c++;
		if (c==3) break;
		res*=10;
	}
	return res==888;
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
  	int n;cin>>n;
  	cout<<192+(n-1)*250<<endl;
  }
 


  return 0;
}