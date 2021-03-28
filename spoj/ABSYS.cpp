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

  int t;cin>>t;while(t--){
    string s[5];
    for(int i=0;i<5;i++){
      cin>>s[i];
    }
    int ind=0;
    for(int i=0;i<5;i++){
      for(int j=0;j<s[i].size();j++){
        if(s[i][j]=='m'){
          ind=i;
          //cout<<i<<" ";
          break;
        }
      }
    }
    if(ind==0) s[ind]=to_string(stoi(s[4])-stoi(s[2]));
    else if(ind==2) s[ind]=to_string(stoi(s[4])-stoi(s[0]));
    else if(ind==4) s[ind]=to_string(stoi(s[0])+stoi(s[2]));
    for(auto x:s){
      cout<<x<<" ";
    }
    cout<<endl;
  }
    
  
  return 0;
}