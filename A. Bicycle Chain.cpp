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
  vector <int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  int m;cin>>m;
  vector <int> b(m);
  for(int i=0;i<m;i++) cin>>b[i]; 
    
  map <int,int,greater<int> > mp;
  for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++){
  		int x=b[j]%a[i];
  		if(x==0){
  			mp[b[j]/a[i]]++;
  		}
  	}
  }
  //for(auto x:mp) cout<<x.F<<" "<<x.S<<endl;
  cout<<mp.begin()->S;
  //   vector <int> c(n+m);
  // sort(a.begin(),a.end());
  // sort(b.begin(),b.end());
  // merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());
  // for(auto x:c) cout<<x<<" ";
  
  return 0;
}