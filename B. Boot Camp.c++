#include <iostream>
#include <vector>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve(){
	int n,k1,k2;cin>>n>>k1>>k2;
	string s;cin>>s;
	int ans[n];
	if(s[0]=='1')
		ans[0]=k1;
	else
		ans[0]=0;
	for(int i=1;i<n;i++){
		if(s[i]=='1' && s[i-1]=='1'){
			ans[i]=k2-ans[i-1];
		}
		else if(s[i]=='1' && s[i-1]=='0'){
			ans[i]=k1;
		}
		else{
			ans[i]=0;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=ans[i];
	cout<<sum<<endl;
	return ;
}

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  int t;cin>>t;while(t--)
  solve();
   
  return 0;
}