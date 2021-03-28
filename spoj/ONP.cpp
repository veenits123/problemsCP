#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int prec(char c){
  	if (c=='^') return 3;
  	if (c=='*' or c=='/') return 2;
  	if (c=='+' or c=='-') return 1;
  	return -1;
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
  	string s;cin>>s;
  	stack<char> st;
  	int n=s.length();
  	string res="";
  	for(int i=0;i<n;i++){
  		if (s[i]>='a' and s[i]<='z'){
  			res+=s[i];
  		}
  		else if (s[i]=='('){
  			st.push(s[i]);
  		}
  		else if (s[i]==')'){
  			while(!st.empty() and st.top()!='('){
  				char c=st.top();
  				st.pop();
  				res+=c;
  			}
  			if (st.top()=='('){
  				char d=st.top();
  				st.pop();
  			}
  		}
  		else{
  			while(!st.empty() and (prec(s[i])<=prec(st.top()))){
  				
  					char e=st.top();
  					st.pop();
  					res+=e;
  			
  			}
  			st.push(s[i]);
  		}
  	}
  	while(!st.empty()){
  		char f=st.top();
  		st.pop();
  		res+=f;
  	}
  	cout<<res<<endl;
  }
    
  
  return 0;
}