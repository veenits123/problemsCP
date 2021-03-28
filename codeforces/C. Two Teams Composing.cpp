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
  	int n;cin>>n;
  	vector <int> a(n);
  	set <int> s;
  	for(int i=0;i<n;i++){
  		cin>>a[i];
  		s.insert(a[i]);
  	}

  	map <int,int> m;
  	map <int,int,greater<int> > neww;

  	for(int i=0;i<n;i++){
  		m[a[i]]++;
  	}

  	for(auto x:m) neww.insert({x.S,x.F});

  	if(neww.begin()->F==s.size()){
  		cout<<s.size()-1<<endl;
  	}
  	else if(neww.begin()->F>s.size()){
  		cout<<s.size()<<endl;
  	}
  	else{
  		cout<<neww.begin()->F<<endl;
  	}

  }
     
  return 0;
}