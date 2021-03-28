#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

bool parity(int x){ 
    int y = x ^ (x >> 1); 
    y = y ^ (y >> 2); 
    y = y ^ (y >> 4); 
    y = y ^ (y >> 8); 
    y = y ^ (y >> 16);
    if (y & 1) return 1; 
    else return 0; 
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
  	int n,q;cin>>n;cin>>q;
  	vector <int> a(n);
  	int od=0,ev=0;
  	for(int i=0;i<n;i++){
  		cin>>a[i];
  		if(parity(a[i])) od++;
  		else ev++;
  	}
  	while(q--){
  		int p;cin>>p;
  		int even=0,odd=0;
  		if(parity(p)==0) {even=ev; odd=n-even;}
  		else{even=od; odd=n-even;}
  		cout<<even<<" "<<odd<<'\n';
  	}
  }
  return 0;
}