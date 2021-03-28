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

  int t;cin>>t;while(t--){
  	int god,mec;cin>>god>>mec;
  	priority_queue <int,vector<int>,greater<int>> gd;
  	priority_queue <int,vector<int>,greater<int>> mc;
  	vector <int> a(god),b(mec);
  	for(int i=0;i<god;i++){
  		cin>>a[i];
  		gd.push(a[i]);
  	}
  	for(int i=0;i<mec;i++){
  		cin>>b[i];
  		mc.push(b[i]);
  	}
  	while(!gd.empty() and !mc.empty()){
  		int g=gd.top();
  		int m=mc.top();
  		gd.pop();
  		mc.pop();
  		if(g>m){
  			gd.push(g);
  		}
  		else if(g==m){
  			gd.push(g);
  		}
  		else{
  			mc.push(m);
  		}
  		if(mc.size()==0){
  			cout<<"Godzilla"<<endl;
  			break;
  		}
  		else if(gd.size()==0){
  			cout<<"MechaGodzilla"<<endl;
  			break;
  		}
  	}
  }
    
  
  return 0;
}