#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

map<int,int>m;
int fun(int i){
    if(m[i])
        return m[i];
    else if(i >(i/2+i/3+i/4)){
        m[i]= i ;
        return i;
    }
    else{
        m[i]= (fun(i/2)+fun(i/3)+fun(i/4));
        return m[i];
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
  //vector<int> a(1000000,0);
  int n;
  while(cin>>n){
  if (n==0) cout<<0<<endl;
  else cout<<fun(n)<<endl;
   } 
  
  return 0;
}