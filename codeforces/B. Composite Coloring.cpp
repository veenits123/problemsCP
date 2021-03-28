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
  vector <int> primes={2,3,5,7,11,13,17,19,23,29,31};

  int t;cin>>t;while(t--){
  	int n;cin>>n;
  	vector <int> a(n);
  	for(int i=0;i<n;i++){
  		cin>>a[i];
  	}
  	vector <int> ans(n,-1);
  
  	int cur_color=1;
  	for(int j=0;j<primes.size();j++){

  		bool type=false;

  		for(int i=0;i<n;i++){
  			if(ans[i]!=-1) continue;

  			if(a[i]%primes[j]) continue;

  			type=true;
  			ans[i]=cur_color;
  		}
  		if(type) cur_color++;
  	}

  	cout<<cur_color-1<<endl;
  	for(auto x:ans) cout<<x<<" ";cout<<endl;

  }
    
  return 0;
}