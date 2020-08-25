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

  //int t;cin>>t;while(t--){}
  int n;cin>>n;
  vector <int> a(n+2);
  for(int i=1;i<=n;i++){
  	cin>>a[i];
  }
  int ind1,ind2,ans=INT_MAX;
  a[n+1]=a[1];
  for(int i=1;i<=n;i++){
  
  	if(ans>abs(a[i]-a[i+1])){
  			ans=abs(a[i]-a[i+1]);
  			ind1=i;
  			if(i==n){
  				ind2=(i+1)%n;
  			}
  			else{
  				ind2=i+1;
  			}
  		}
  }
  cout<<ind1<<" "<<ind2;
  
  
  return 0;
}