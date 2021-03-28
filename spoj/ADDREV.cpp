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
  int start_s=clock();
	// the code you wish to time goes here


  int t;cin>>t;while(t--){
  	string s1,s2;cin>>s1>>s2;
  	int n1=s1.length(),n2=s2.length();
  	string ss1="",ss2="";
  	for(int i=0;i<n1;i++){
  		ss1+=s1[n1-i-1];
  	}
  	for(int i=0;i<n2;i++){
  		ss2+=s2[n2-i-1];
  	}
  	//cout<<ss1<<" "<<ss2;
  	 int k1=stoi(ss1),k2=stoi(ss2);
  	int k=k1+k2;
  	string res=to_string(k),ans="";
  	for(int i=0;i<res.length();i++){
  		ans+=res[res.length()-i-1];
  	}
  	cout<<stoi(ans)<<endl;
  	}
  	int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    
  
  return 0;
}