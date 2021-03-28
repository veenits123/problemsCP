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

  //int t;cin>>t;while(t--){
  int n;
  while(1){
  	cin>>n;
  	if(n==0) return 0;
  	vector <int> a(n+1),b(n+1,0);
  	for(int i=1;i<=n;i++){
  		cin>>a[i];
  		b[a[i]]=i;
  	}
  	bool flag=true;
  	for(int i=1;i<=n;i++){
  		if(a[i]!=b[i]){
  			flag=false;
  			break;
  		}
  	}
  	// for(int i=1;i<=n;i++){
  	// 	cout<<b[i]<<" ";
  	// }cout<<endl;
  	if(flag) cout<<"ambiguous"<<endl;
  	else cout<<"not ambiguous"<<endl;
  }
    
  
  return 0;
}