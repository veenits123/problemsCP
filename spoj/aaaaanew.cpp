#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

//brute force solution
void solve(){
   int t;cin>>t;while(t--){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    int c=0;
    for(int i=0;i<n;i++){
      for(int j=i;j<n;j++){
        if(a[i]>a[j] and i<j) c++;
      }
    }
    cout<<c<<endl;
  }
}

//using merge-sort i.e. divide & conquer ;)
int merge(int a[],int temp[],int left,int mid,int right){
  int i=left, j=mid, k=left;
  int inversion=0;
  //int temp[right];
  while(i<=mid-1 and j<=right){
    if (a[i]<=a[j]){
      temp[k]=a[i];
      i++;k++;
    }
    else{
      temp[k]=a[j];
      //counting inversion during merging
      inversion += mid-i;
      j++;k++; 
    }
  }
  while(i<=mid-1){
    temp[k]=a[i];
    i++;k++;
  }
  while(j<=right){
    temp[k]=a[j];
    j++;k++;
  }
  for(int i=left;i<=right;i++){
    a[i]=temp[i];
  }
  return inversion;
}

int merge_sort(int a[],int temp[],int left,int right){
  int inversion=0;
  int mid;
  if(left<right){
    mid=(left+right)/2;
    //counting inversion in left part
    inversion += merge_sort(a,temp,left,mid);
    //cout<<inversion<<"l ";
    //counting inversion in right part
    inversion += merge_sort(a,temp,mid+1,right);
    //cout<<inversion<<"r ";
    //merging the two parts
    inversion += merge(a,temp,left,mid+1,right);
    //cout<<inversion<<"m ";
  }
  return inversion;
}

int count_inversion(int a[],int n){
  int temp[n];
  return merge_sort(a,temp,0,n-1);
}

//inversion using set C++ stl
int inversion_set(int a[],int n){
  set<int>s;
  s.insert(a[0]);
  int inversion=0;
  for(int i=1;i<n;i++){
    s.insert(a[i]);
    auto it = s.upper_bound(a[i]);
    inversion+=distance(it,s.end());
  }
  return inversion;
}

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts
  //solve();
  int t;cin>>t;while(t--){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    //cout<<count_inversion(a,n)<<endl;
    //cout<<merge_sort(a,0,n-1)<<endl;
    cout<<inversion_set(a,n)<<endl;
 }
  
  return 0;
}