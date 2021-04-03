#include<bits/stdc++.h>
using namespace std;

//#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e5+7;
int tree[4 * N];
int a[N];

void build_tree_sum(int start, int end, int pos) {
	if (start == end) {
		tree[pos] = a[start];
		return ;
	}
	int mid = (start + end) / 2;

	build_tree_sum(start, mid, 2 * pos);
	build_tree_sum(mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

int range_query_sum(int q_low, int q_high, int start, int end, int pos) {

	if (q_low <= start and q_high >= end) {
		return tree[pos];
	}

	if (q_low > end or q_high < start) {
		return 0;
	}

	int mid = (start + end) / 2;
	int left = range_query_sum(q_low, q_high, start, mid, 2 * pos);
	int right = range_query_sum(q_low, q_high, mid + 1, end, 2 * pos + 1);

	return left + right;
}

void update(int index, int val, int start, int end, int pos) {

	if (index<start or index>end) {
		return ;
	}
	if (start == end) {
		tree[pos] = val;
		return ;
	}
	int mid = (start + end) / 2;

	update(index, val, start, mid, 2 * pos);
	update(index, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

void sum_update(int index, int val, int start, int end, int pos) {

	if (index<start or index>end) {
		return ;
	}
	if (start == end) {
		tree[pos] += val;
		return ;
	}
	int mid = (start + end) / 2;

	sum_update(index, val, start, mid, 2 * pos);
	sum_update(index, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

inline int nextint() { int x; scanf("%d", &x); return x; }

int main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  // code starts

  int t=nextint();for(int i=1;i<=t;i++){
  	int n=nextint();
  	int q=nextint();
  	for(int i=0;i<n;i++){
  		a[i]=nextint();
  	}
  	printf("Case %d:\n",i);
  	build_tree_sum(0,n-1,1);
  	while(q--){
  		int x=nextint();
  		if(x==1){

  			int y=nextint();
  			printf("%d\n",range_query_sum(y,y,0,n-1,1));
  			update(y,0,0,n-1,1);
  		}
  		else if(x==2){
  			int ind=nextint();
  			int val=nextint();
  			sum_update(ind,val,0,n-1,1);
  		}
  		else{
  			int l=nextint();
  			int r=nextint();
  			printf("%d\n",range_query_sum(l,r,0,n-1,1));
  		}
  	}
  }
    
  
  return 0;
}