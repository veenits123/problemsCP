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
  vector <P> moves;
  moves.pb({1,1});moves.pb({2,2});moves.pb({3,3});moves.pb({4,4});
  moves.pb({5,5});moves.pb({6,6});moves.pb({7,7});moves.pb({8,8});moves.pb({7,7});
  moves.pb({6,8});moves.pb({5,7});moves.pb({4,6});moves.pb({3,5});moves.pb({2,4});
  moves.pb({1,3});moves.pb({2,4});moves.pb({1,5});moves.pb({2,6});moves.pb({3,7});
  moves.pb({4,8});moves.pb({3,7});moves.pb({2,8});moves.pb({1,7});moves.pb({2,6});moves.pb({3,5});
  moves.pb({4,4});moves.pb({5,3});moves.pb({6,2});moves.pb({7,1});moves.pb({8,2});
  moves.pb({7,3});moves.pb({8,4});moves.pb({7,5});moves.pb({8,6});moves.pb({7,5});
  moves.pb({6,4});moves.pb({5,3});moves.pb({4,2});moves.pb({5,1});moves.pb({4,2});
  moves.pb({3,1});
  moves.pb({2,2});

  int t;cin>>t;while(t--){
  	int r,c;cin>>r>>c;
  	if (r==1 and c==1){
  		cout<<moves.size()<<endl;
  		for(auto x:moves){
  			cout<<x.F<<" "<<x.S<<endl;
  		}
  	}
  	else{
  	auto p=make_pair(r,c);
  	auto it=find(moves.begin(),moves.end(),p);
  	auto x=it-moves.begin();
  	//cout<<x<<endl;
  	cout<<43<<endl;
  	for(int i=x-1;i<moves.size();i++){
  		cout<<moves[i].F<<" "<<moves[i].S<<endl;
  	}
  	//cout<<endl;
  	for(int i=0;i<x;i++){
  		cout<<moves[i].F<<" "<<moves[i].S<<endl;
  	}}
  	

  }
  return 0;
}