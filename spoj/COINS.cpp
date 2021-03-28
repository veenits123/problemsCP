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
  int n;cin>>n;
  while(n){

  	string s;cin>>s;
  	int row=s.length()/n;
  	char ans[row][n];
  	int k=0;
  	for(int i=0;i<row;i++){
  		if (i&1){
  			for(int j=n-1;j>=0;j--){
  				ans[i][j]=s[k++];
  			}
  		}
  		else {
  			for(int j=0;j<n;j++){
  				ans[i][j]=s[k++];
  			}
  		}
  	}
  	for(int i=0;i<n;i++){
  		for(int j=0;j<row;j++){
  			cout<<ans[j][i];
  		}
  	}
  	cout<<endl;
  	cin>>n;
  }

    
  
  return 0;
}