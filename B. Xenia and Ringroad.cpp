#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int sum(int a[],int n){
	int sm=0;
	for(int i=0;i<n;i++){
		sm+=a[i];
	}
	return sm;
}
int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  //int t;cin>>t;while(t--){}
  int n,m;cin>>n>>m;
  int a[m];
  for(int i=0;i<m;i++){
  	cin>>a[i];
  }
  int ans=0;
  int b[m];
  b[0]=a[0]-1;
  for(int i=1;i<m;i++){
  	int x=a[i]-a[i-1];
  	if(x>=0){
  		b[i]=x;
  	}
  	else{
  		b[i]=(n-a[i-1]);
  		//cout<<b[i]<<endl;
  		b[i]+=a[i];
  		//cout<<b[i]<<endl;
  	}
  }
  
  cout<<sum(b,m);
    
  
  return 0;
}