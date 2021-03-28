#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int mostFreq(int arr[], int n) 
{ 
    // Insert all elements in hash. 
    unordered_map<int, int> hash; 
    for (int i = 0; i < n; i++) 
        hash[arr[i]]++; 
  
    // find the max frequency 
    int max_count = 0, res = -1; 
    for (auto i : hash) { 
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        } 
    } 
  
    return res; 
} 

int leastFreq(int arr[], int n) 
{ 
    // Insert all elements in hash. 
    unordered_map<int, int> hash; 
    for (int i = 0; i < n; i++) 
        hash[arr[i]]++; 
  
    // find the min frequency 
    int min_count = n+1, res = -1; 
    for (auto i : hash) { 
        if (min_count >= i.second) { 
            res = i.first; 
            min_count = i.second; 
        } 
    } 
  
    return res; 
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
  	
  	int n,m,k;cin>>n>>m>>k;

    vector <int> a(n+1);
       
    for(int i=1;i<=n;i++){
       int b[k];
       memset(b,0,k);

      for(int j=0;j<k;j++){
        cin>>b[j]; 
      }
      int x=mostFreq(b,k);
      bool flag=true;
      for(int t=1;t<=m;t++){
        if(x!=t){
          a[i]=t;
          flag=false;
        }
      }
      if(flag) a[i]=x;
      
      }
  
    for(int i=1;i<=n;i++){
      cout<<a[i]<<" ";
    }
    cout<<endl;
    

  }    
  
  return 0;
}