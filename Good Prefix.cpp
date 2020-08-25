#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

class gfg 
{ 
 public : int gcd(int a, int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
  
   
// Function to return LCM of two numbers  
  int lcm(int a, int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  
} ; 

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  int t;cin>>t;while(t--){
  	int n,k;cin>>n>>k;
  	vector <int> a(n);
  	gfg g;
  	
  	for(int i=0;i<n;i++){
  		cin>>a[i];
  	}
  	//sort(a.begin(),a.end());
  	int l=g.lcm(a[0],a[1]);
  	for(int i=0;i<n;i++){
  		l=g.lcm(l,a[i]);
  	}
  	int mx=l,pos=1;
  	for(int i=1;i<=k;i++){
  		int x=g.lcm(l,i);
  		if(x>mx){
  			mx=x;
  			pos=i;
  		}
  	}
  	cout<<pos<<endl;
 
  }
    
  
  return 0;
}