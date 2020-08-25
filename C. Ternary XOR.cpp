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

  int t;cin>>t;while(t--){
  	int n;cin>>n;
  	string s;cin>>s;
  	string low="",high="";
  	int i=0;
  	for(i=0;i<n;i++){
  		if(s[i]=='2'){
  			low+='1';
  			high+='1';
  		}
  		else if(s[i]=='0'){
  			low+='0';
  			high+='0';
  		}
  		else{
  			high+='1';
  			low+='0';
  			break;	
  		}
  	}
  	//cout<<high<<" "<<low<<endl;
  	int j=i;
  	for(j=i+1;j<n;j++){
  		low+=s[j];
  		high+='0';
  		//cout<<high<<" "<<low<<endl;
  	}
  	cout<<high<<endl;
  	cout<<low<<endl;
  }
    
  
  return 0;
}