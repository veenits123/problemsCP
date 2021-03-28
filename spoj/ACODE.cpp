#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

//big integer summation
string add(string a,string b){
	if (a.length()>b.length()) swap(a,b);

  int al=a.length(),bl=b.length();
 
  string ans="";
  int carry=0;
  int i=al-1;
  while(i>=0){

  	int sum=(a[i]-'0'+b[i+bl-al]-'0'+carry);
  	ans.pb(sum%10+'0');
  	carry=sum/10;
  	
  	i--;
  }
  int j=bl-al-1;
  while(j>=0){

  	int sum=(b[j]-'0'+carry);
  	ans.pb(sum%10+'0');
  	carry=sum/10;

  	j--;
  }
  if (carry) ans.pb(carry+'0');

  reverse(ans.begin(),ans.end());

 return ans;
}

//check if string is smaller
bool chcek_small(string a,string b){
	if (a.length()>b.length()) return false;
	if (a.length()<b.length()) return true;

	int n1=a.length();
	for(int i=0;i<n1;i++){
		if (a[i]<b[i]) return true;
		else if (a[i]>b[i]) return false;
	}
	return false;
}

//big int subtraction
string sub(string a,string b){
	string ans="";
	int neg=0;
	if (chcek_small(a,b)) {swap(a,b); neg=1;};
	
	int carry=0;
	int n1=a.length(),n2=b.length();
	int i=n2-1;
	while(i>=0){
		int sub=(a[i+n1-n2]-'0')-(b[i]-'0')-carry;
		if (sub<0){
			sub+=10;
			carry=1;
		}
		else {
			carry=0;
		}
		ans.pb(sub+'0');
		i--;
	}
	int j=n1-n2-1;
	while(j>=0){
		int sub=(a[j]-'0')-carry;
		if (a[j]=='0' and carry) ans.pb('9');
		if (sub>0) ans.pb(sub+'0');
		carry=0;
		j--;
	}
	if (neg) ans.pb('-');
	reverse(ans.begin(),ans.end());

	return ans;
}

//big integer multiplication
// string multiply(string a,string b){

// }

//big integer division
string divide(string dividend,int divisor){
	string ans;
	int index=0;
	int temp=dividend[index]-'0';
	while(temp<divisor){
		temp=temp*10+dividend[++index]-'0';
	}
	while(index<dividend.length()){
		ans+=(temp/divisor)+'0';
		temp=(temp%divisor)*10+dividend[++index]-'0';
	}
	if (ans.length()==0) return "0";
	return ans;
}

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  for(int i=0;i<2;i++){
  	string n,d;cin>>n>>d;
  	string a,b;
  	a=divide(add(n,d),2);
  	b=sub(n,a);
  	cout<<a<<endl<<b<<endl;
 }
  
  return 0;
}




