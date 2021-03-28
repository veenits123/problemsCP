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

  while(1){
    double x,len=0.00;cin>>x;
    if (x==0.00) break;
    int n=0;
    while(x>len){
        n++;
        len+=1.00/(n+1.00);
    }
    cout<<n<<" card(s)"<<endl;

  }
  
  return 0;
}