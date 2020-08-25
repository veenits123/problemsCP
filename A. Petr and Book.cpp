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
  vector <P> a(8,{0,0});
  queue <P> q;
  for(int i=1;i<=7;i++){
  	a[i].F=i;
  	cin>>a[i].S;
  	q.push(a[i]);
  }
  int ans=0;
  while(!q.empty()){
  	P cur=q.front();
  	int pg=cur.S,day=cur.F;
  	q.pop();
  	n-=pg;
  	if(n>0){
  		q.push({day,pg});
  	}
  	else{
  		ans=day;
  		break;
  	}
  }
  cout<<ans;
  

    
  
  return 0;
}