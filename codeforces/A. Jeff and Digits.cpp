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
  int a[n];
  map <int,int> m;
  for(int i=0;i<n;i++){
  	cin>>a[i];
  	m[a[i]]++;
  }
  bool flag=false;
  int no=0,zero=0;
  for(auto x:m){
  	if(x.F==0){
  		flag=true;
  		zero=x.S;
  	}
  	if(x.F==5 and x.S>=9){
  		no=x.S;
  	}
  }
  if(flag==false) cout<<-1;
  
  else if(no==0) cout<<0;
  else{
  int ins=no%9;
  no=no-ins;
  for(int i=0;i<no;i++){
  	cout<<5;
  }
  for(int i=0;i<zero;i++){
  	cout<<0;
  }
}




    
  
  return 0;
}