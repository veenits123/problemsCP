#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

bool sortbysec(pair<string,int> a,pair<string,int> b){ 
    return (a.second < b.second); 
} 

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
    map<int,string> m;
    //vector<pair<string,int> > a(n);
    while(n--){
      string s;int tim;cin>>s>>tim;
      m[tim]=s;
      //a.pb({s,tim});
    }
    //sort(a.begin(),a.end(),sortbysec);
    // for(auto x:a){
    //   cout<<x.F<<endl;
    // }

    for(auto x:m){
      cout<<x.S<<endl;
    }
  }
    
  
  return 0;
}