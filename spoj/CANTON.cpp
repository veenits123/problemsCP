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
  	int n;cin>>n;
  	int i=1,j=1,k=1;
  	while(k<n){
  		j++;k++;
  		if(k==n) break;
 
  		while(j>1 and k<n){
  			j--;i++;k++;
  		}
  		if(k==n) break;
  		i++;k++;
  		if(k==n) break;
  		while(i>1 and k<n){
  			i--;j++;k++;
  		}
  	}
  	
  	cout<<"TERM "<<n<<" IS "<<i<<"/"<<j<<endl;
  }
    
  
  return 0;
}