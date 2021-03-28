#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
int mod=1000000007;

int val(char c){
  if(c=='7' or c=='9') return 4;
  else return 3;
}

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  map<int,int>key;
  for(int i=2;i<=9;i++){
    if(i==7) key[i]=4;
    else if(i==9) key[i]=4;
    //else if(i==1) key[i]=0;
    else{
      key[i]=3;
    }
  }

  int t;cin>>t;while(t--){
    //int n;cin>>n;
    string s;cin>>s;
    //int n=stoi(s);
    int ans=1;
    //map<int,int> :: iterator itr;
    // while(n>0){
    //   int rem=n%10;
    //   if(rem==1) ans-=3;
    //   else ans=ans*key[rem];
    //   n=n/10;
    // }
    for(auto x:s){
      ans=(ans*val(x))%mod;
      //ans%=mod;
    }
    cout<<ans%mod<<endl;
  }
    
  
  return 0;
}