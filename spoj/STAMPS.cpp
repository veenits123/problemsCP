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

  int t;cin>>t;int tc=t;while(t--){
    int total,n;cin>>total>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    int ans=0,c=0;
    if (sum<total) cout<<"Scenario #"<<tc-t<<":"<<endl<<"impossible"<<endl;
    else{
    for(auto x:a){
        ans+=x;
        c++;
        if (ans>=total) break;
    }
    cout<<"Scenario #"<<tc-t<<":"<<endl<<c<<endl;
  }
}
    
  
  return 0;
}