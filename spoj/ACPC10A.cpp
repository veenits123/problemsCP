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

  	int n;cin>>n;
  	while(n!=-1){
  		int a[n],sum=0,ans=0;
  		for(int i=0;i<n;i++){
  			cin>>a[i];
  			sum+=a[i];
  		}
  		int avg=sum/n;
  		if (sum==avg*n){
  			for(int i=0;i<n;i++){
  				if (a[i]<avg){
  					ans+=avg-a[i];
  				}
  			}
  			cout<<ans<<endl;
  		}
  		else{
  			cout<<-1<<endl;
  		}

  		cin>>n;
  	}
  	
 
  
    
  
  return 0;
}