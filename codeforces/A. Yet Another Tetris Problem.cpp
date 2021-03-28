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

  int t;cin>>t;while(t--){
  	int n;cin>>n;
  	vector <int> a(n);
  	for(int i=0;i<n;i++){
  		cin>>a[i];
  	}
  	sort(a.begin(),a.end());
  	int mx=a[n-1];
  	int c=1;
  	for(int i=0;i<n;i++){
  		if(a[i]%2==1 and mx%2==0) c=0;
  		if(a[i]%2==0 and mx%2==1) c=0;
  	}
  	if(c) cout<<"YES"<<endl;
  	else cout<<"NO"<<endl;
  }
    
  
  return 0;
}