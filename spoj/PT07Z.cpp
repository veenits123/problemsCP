#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=10001;

vector <vector<int>> tree(N);
int m=-1,q=0;

void dfs(int source, int count, vector<bool>& visited){
	count++;
	visited[source]=true;
	for(int i=0;i<tree[source].size();i++){
		int cur=tree[source][i];
		if(visited[cur]) continue;
		dfs(cur,count,visited);
	}
	if(count>m){
		m=count;
		q=source;
	}
}

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

  vector <bool> v(n);//to apply dfs 1st time
  //fill(v.begin(),v.end(),false);

  vector <bool> visited(n);//to apply dfs 2nd time

  for(int i=0;i<n-1;i++){
  	int x,y;cin>>x>>y;
  	tree[x].pb(y);
  	tree[y].pb(x);
  }
  dfs(1,0,v);
  //m=-1;
  //cout<<q<<endl;
  dfs(q,0,visited);
  //cout<<q<<endl;
  cout<<m-1;

    
  
  return 0;
}