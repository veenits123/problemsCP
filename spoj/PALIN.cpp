#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

string next_pallin(string s,string r){
	int n=s.length();
	r=s;
	for(int i=n/2;i<n;i++){
		r[i]=r[n-i-1];
	}
	if (r>s){
		return r;
	}
	for(int i=(n-1)/2;i>=0;i--){
		if (r[i]!='9'){
			r[i]++;
			break;
		}
		r[i]='0';
	}
	for(int i=n/2;i<n;i++){
		r[i]=r[n-i-1];
	}
	if (r[0]=='0'){
		r[0]='1';
		r+='1';
	}
	return r;
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
  	string s,r;cin>>s;
  	r=s;
  	cout<<next_pallin(s,r)<<endl;
  }
  
  return 0;
}