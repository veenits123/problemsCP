#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
//#define P pair<int,int>
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

bool almost_prime(int n,int k){
  vector <int> factors;
  int i=0,pr=primes[i];
  while(pr*pr<=n){
  	if(n%pr==0){
  		factors.pb(pr);
  		while(n%pr==0){
  			n=n/pr;
  		}
  	}
  	i++;
  	pr=primes[i];
  }
  if(n!=1) factors.pb(n);

  if(factors.size()==k){
  	return true;
  }
  else {
  	return false;
  }
}

vector <int> factors[100001],prime_factors(100001);
bool strange(int x,int k){
	
	//factors
	for(int i=1;i<=100001;i++){
		for(int j=1;j<=100001;j++){
			if(i%j==0){
				factors[i].pb(j);
			}
		}
	}

	//prime factors
	for(int i=1;i<=100001;i++){
		if(almost_prime(i,k)){
			prime_factors[i]=1;
		}
		else{
			prime_factors[i]=0;
		}
	}
	bool flag=false;
	for(int i=1;i<=100001;i++){
		if(factors[i].size()==x and prime_factors[i]==1){
			flag=true;
			break;
		}
	}
	
	return flag;


}

bool kFactors(int n, int k) 
{ 
    // A vector to store all prime factors of n 
    vector<int> P; 
  
    // Insert all 2's in vector 
    while (n%2 == 0) 
    { 
        P.push_back(2); 
        n /= 2; 
    } 
  
    // n must be odd at this point 
    // So we skip one element (i = i + 2) 
    for (int i=3; i*i<=n; i=i+2) 
    { 
        while (n%i == 0) 
        { 
            n = n/i; 
            P.push_back(i); 
        } 
    } 
  
    // This is to handle when n > 2 and 
    // n is prime 
    if (n > 2) 
        P.push_back(n); 
  
    // If size(P) < k, k factors are not possible 
    if (P.size() < k) 
    { 
        //cout << "-1" << endl; 
        return false; 
    } 
  
    else return true;
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
  	int x,k;cin>>x>>k;

  	
  	if(kFactors(x,k)) cout<<1<<endl;
  	else cout<<0<<endl;

  	//if(flag) cout<<1<<endl;
  	//else cout<<0<<endl;


  }
    
  
  return 0;
}