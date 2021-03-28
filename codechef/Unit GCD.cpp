#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

vector <int> primes;
const int N=100001;
int a[N]={0};

bool is_prime(int n){
	a[0]=0,a[1]=0,a[2]=1;
	for(int i=3;i<=n;i++){
		if(i&1){
			a[i]=1;
		}
	}
	for(int i=3;i<=n;i++){
		if(a[i]==1){
			for(int j=i*i;j<=n;j+=2*i){
				a[j]=0;
			}
		}
	}
	if(a[n]){
		return true;
	}
	else{
		return false;
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
  	int n;cin>>n;
  	
  	vector <int> a[n/2+1];
  	int i;
  	if(n==1){
  		cout<<1<<endl;
  		cout<<1<<" "<<1<<endl;
  	}
  	else if(n&1){
  		cout<<n/2<<endl;
  	for(i=1;i<=n;i+=2){
  		if(i<n-2) cout<<2<<" "<<i<<" "<<i+1<<endl;
  		else cout<<3<<" "<<i<<" "<<i+1<<" "<<i+2<<endl;
  		if(i==n-2) break;
  	}}
  	else{
  		cout<<n/2<<endl;
  		for(i=1;i<=n;i+=2){
  		if(i<n-2) cout<<2<<" "<<i<<" "<<i+1<<endl;
  		else cout<<2<<" "<<i<<" "<<i+1<<endl;
  		if(i==n-2) break;
  	}
  }




  }
    
  
  return 0;
}