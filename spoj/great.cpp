#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

void print(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<" "<<a[i];
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

  int t;cin>>t;while(t--){
    int n,p;cin>>n>>p;
    vector <int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int>m;
    for(auto x:a){
      m[x]=0;
    }
    int c=0,knha=0;
    for(int i=0;i<n;i++){
      if (a[i+1]%a[i]==0 and p%a[i]==0){
        c++;
      }
      else{
        knha=i;
        m[a[i]]=1;
      }
    }
    for (auto x:m) cout<<x.S<<" ";cout<<endl;
    if (c==n) cout<<"NO"<<endl;
    // else{
    //   map<int,int> m2;
    //   for(auto x:a) m2[x]=0;
    //   cout<<"YES ";
    //   int price=0;
    //   while(1){
    // for(auto x:m){
    //   if (x.S==1){
    //     price+=x.F;
    //     m2[x.F]++;
    //   }
    //   else{

    //   }
    //   if (p<price) break;
    // }if (p<price) break;}
    // for (auto x:m2){
    //   cout<<x.S<<" ";}
    //   cout<<endl;
    // }   
  
}
  return 0;
}