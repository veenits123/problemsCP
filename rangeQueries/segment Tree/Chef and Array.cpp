#include <iostream>
//#include <climits>

using namespace std;

#define int long long int
#define endl '\n'

const int N = 1e5+5;
int tree[4 * N];
int a[N];

void build(int start, int end, int pos) {
  if(start>end) return ;
  if (start == end) {
    tree[pos] = a[start];
    return ;
  }
  int mid = (start + end) / 2;

  build(start, mid, 2 * pos);
  build(mid + 1, end, 2 * pos + 1);

  tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
  return ;
}

int query(int q_low, int q_high, int start, int end, int pos) {
  if (q_low <= start and q_high >= end) {
    return tree[pos];
  }
  if (q_low > end or q_high < start || start>end) {
    return -1;
  }
  int mid = (start + end) / 2;
  int left = query(q_low, q_high, start, mid, 2 * pos);
  int right = query(q_low, q_high, mid + 1, end, 2 * pos + 1);

  return max(left, right);
}

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  //int t;cin>>t;while(t--){}
  int n;cin>>n;
  for(int i=0;i<n;i++){
  	cin>>a[i];
  }
  build(0,n-1,1);
  int m,x,y;cin>>m>>x>>y;
  int ans=0;
  ans+=query(min(x,y),max(x,y),0,n-1,1);
  //cout<<ans<<endl;
  for(int i=2;i<=m;i++){
    
  	int xx=(x+7)%(n-1);
  	int yy=(y+11)%n;
    //cout<<xx<<" "<<yy<<endl;
      ans+=query(min(xx,yy),max(xx,yy),0,n-1,1);
  
    //cout<<ans<<endl;

    x=xx;y=yy;
  }
  cout<<ans<<endl;
    
  
  return 0;
}