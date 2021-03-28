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

 	bool flag=true;
  	for(int i=0;i<n;i++){
  		if(a[i]==1){
  			int c=0;
  			for(int j=i+1;j<n;j++){
  				c++;
  				if(a[j]==1 and c<=5){
  					flag=false;
  					break;
  				}
  			}
  		}
  	}
  	if(flag) cout<<"YES"<<endl;
  	else cout<<"NO"<<endl;
  }
    
  
  return 0;
}