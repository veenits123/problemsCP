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

  //int t;cin>>t;while(t--){
  while(1){
    int n;cin>>n;
    if (n==0) break;
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    stack<int> s;
    int c=1,need=1;
    for(int i=0;i<n;i++){
      while(!s.empty() and s.top()==need){
        need++;
        s.pop();
      }
      if (a[i]==need){
        need++;
      }
      else if(!s.empty() and a[i]>s.top()){
        c=0; break;
      }
      else{
        s.push(a[i]);
        //cout<<s.top()<<" ";
      }
    }
    if (c) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    
  }
  return 0;
}