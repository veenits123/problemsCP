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
  int n,m;cin>>n>>m;
  int a[n+1];
  queue <P> q;
  for(int i=1;i<=n;i++){
  	cin>>a[i];
  	q.push({i,a[i]});
  }
  int ans=0;
  while(!q.empty()){
  	P cur=q.front();
  	int i=cur.F,c=cur.S;
  	q.pop();
  	//cout<<i<<" "<<c<<endl;
  	if(c>m){
  		c-=m;
  		q.push({i,c});
  	}
  	ans=i;
  }
  cout<<ans;
    
  
  return 0;
}