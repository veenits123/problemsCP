#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7;
int a[maxn];
int tree[4*maxn];



void build_tree_min(int start,int end,int pos){
	if(start==end){
		tree[pos]=a[start];
		return ;
	}
	int mid=(start+end)/2;

	build_tree_min(start,mid,2*pos);
	build_tree_min(mid+1,end,2*pos+1);

	tree[pos]=min(tree[2*pos],tree[2*pos+1]);
	return ;
}

int range_query_min(int q_low,int q_high,int start,int end,int pos){
	if(q_low<=start and q_high>=end){
		return tree[pos];
	}
	if(q_low>end or q_high<start){
		return INT_MAX;
	}
	int mid=(start+end)/2;
	int left=range_query_min(q_low,q_high,start,mid,2*pos);
	int right=range_query_min(q_low,q_high,mid+1,end,2*pos+1);

	return min(left,right);
}
//take faster input
inline int nextint(){ int x; scanf("%d",&x); return x; }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
	int t = nextint();
	for(int i = 1; i <= t; i++)
	{
		printf("Case %d:\n",i);
		int n = nextint();
		int q = nextint();
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		build_tree_min(0,n-1,1);
		while(q--)
		{
			int l = nextint();
			int r = nextint();
			printf("%d\n",range_query_min(l-1,r-1,0,n-1,1));
		}
	}


    return 0;
}
