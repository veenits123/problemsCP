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
  	int a,b,c,d;cin>>a>>b>>c>>d;
  	int x,y,x1,y1,x2,y2;cin>>x>>y>>x1>>y1>>x2>>y2;

  	int ans=0;

  	x+=-a+b;y+=-c+d;
  	
  	if((x>=x1 and x<=x2) and (x1<x2 or a+b==0) and (y>=y1 and y<=y2)
  	 and (y1<y2 or c+d==0))
  		ans=1;
  	if(ans) cout<<"Yes"<<endl;
  	else cout<<"No"<<endl;
  }
    
  
  return 0;
}