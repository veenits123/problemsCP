#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

bool check(int a[],int n,int c,int dist){
	int count=1;
	int last=a[0];
	for(int i=1;i<n;i++){
		if (a[i]-last>=dist){
			last=a[i];
			count++;
		}
		if (count==c) return true;
	}
	return false;
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
  	int n,c;cin>>n>>c;
  	int a[n];
  	for(int i=0;i<n;i++){
  		cin>>a[i];
  	}
  	sort(a,a+n);
  	int ans=-1;
  	int max=a[n-1]-a[0],min=a[0];
  	while(min<=max){
  
  		int mid=(min+max)/2;
  		if (check(a,n,c,mid)){
  			ans=mid;
  			min=mid+1;
  		}
  		else {
  			max=mid-1;
  		}
  	}
  	cout<<ans<<endl;
  }
    
  
  return 0;
}