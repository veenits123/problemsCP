
/*              `-._:  .:'   `:::  .:\            |\__/|           /::  .:'   `:::  .:.-'
                    \      : V         \          |:   |          /         : T      /    
                     \     ::    .     `-_______/ ::   \_______-'   .      ::   . /      
                      |  :   :: ::'  :   :: ::'  :   :: ::'    N  :: ::'  :   :: :|       
                      |     ;::        E ;::         ;::         ;::         ;::  |       
                      |  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:|       
                      /     :           :         E  :           :     I      :    \       
                     /______::_____     ::    .     ::    .     ::   _____._::____\      
                                   `----._:: ::'  :   :: ::'  _.----'                    
                                          `--.       ;::  .--'                           
                                              `-. .:'  .-'                               
                                                 \    /                        
                                                  \  /                                   
                                                   \/  */             
                
// Author : vee_nits123
#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define pbk pop_back
#define PI 3.1415926535897932384626
#define endl '\n'
const int mod = 1000000007;
const int N=100005;

void the_Bloombug(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define scanarr(a,b,c) for( i=b;i<c;i++)cin>>a[i]
#define showarr(a,b,c) for( i=b;i<c;i++)cout<<a[i]<<' '
#define ln cout<<'\n'


void solve(){
	int N,i,j,P,pos1=-1,pos2=-1,mn,mx;
	cin>>N>>P;
	int D[N];
	bool isPossib=false;

	for(i=0;i<N;i++){
		cin>>D[i];
		if(D[i]>P)
			pos1=i;
		if(P%D[i]!=0)
			pos2=i;
	}

	if(pos1!=-1){
		cout<<"YES ";
		for(i=0;i<N;i++){
			if(i==pos1)
				cout<<1<<" ";
			else
				cout<<0<<" ";
		}
		ln;
		return;
	}
	if(pos2!=-1){
		cout<<"YES ";
		for(i=0;i<N;i++){
			if(i==pos2)
				cout<<(P/D[i])+1<<" ";
			else
				cout<<0<<" "; 
		}
		ln;
		return;
	}
	
	for(i=0;i<N&&!isPossib;i++){
		for(j=i+1;j<N&&!isPossib;j++){
			mn=D[i]<D[j]?i:j;
			mx=i==mn?j:i;
			if(D[mn]!=1&&D[mx]!=1&&D[mx]%D[mn]!=0){
				pos1=mn;
				pos2=mx;
				isPossib=true;
			}			
		}
	}
	if(isPossib){
		cout<<"YES ";
		for(i=0;i<N;i++){
			if(i==mn){
				cout<<((P%D[mx]+(P%D[mx]==0?D[mx]:0))/D[mn])+1<<" ";

			}
			else if(i==mx){
				cout<<P/D[mx]-(P%D[mx]==0?1:0)<<" ";
				
			}
			else{
				cout<<0<<" ";
			}			
		}
		ln;
		return;
	}
	cout<<"NO"<<endl;	
	
}


int32_t main(){
  
  the_Bloombug();
  
  int t;cin>>t;while(t--){
  	solve();
  }


  return 0;
}