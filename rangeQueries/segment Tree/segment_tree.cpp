#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e5+5;
int tree[4 * N];
int a[N];
int lazy[4*N];

void build_tree_min(int start, int end, int pos) {
	if (start == end) {
		tree[pos] = a[start];
		return ;
	}
	int mid = (start + end) / 2;

	build_tree_min(start, mid, 2 * pos);
	build_tree_min(mid + 1, end, 2 * pos + 1);

	tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

void build_tree_sum(int start, int end, int pos) {
	if (start == end) {
		tree[pos] = a[start];
		return ;
	}
	int mid = (start + end) / 2;

	build_tree_sum(start, mid, 2 * pos);
	build_tree_sum(mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] ^ tree[2 * pos + 1];
	return ;
}

int range_query_min(int q_low, int q_high, int start, int end, int pos) {
	if (q_low <= start and q_high >= end) {
		return tree[pos];
	}
	if (q_low > end or q_high < start) {
		return INT_MAX;
	}
	int mid = (start + end) / 2;
	int left = range_query_min(q_low, q_high, start, mid, 2 * pos);
	int right = range_query_min(q_low, q_high, mid + 1, end, 2 * pos + 1);

	return min(left, right);
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

	return left ^ right;
}

void update_min(int index, int val, int start, int end, int pos) {

	if (index<start or index>end) {
		return ;
	}
	if (start == end) {
		tree[pos] = val;
		return ;
	}
	int mid = (start + end) / 2;

	update_min(index, val, start, mid, 2 * pos);
	update_min(index, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

void update_sum(int index, int val, int start, int end, int pos) {

	if (index<start or index>end) {
		return ;
	}
	if (start == end) {
		tree[pos] = val;
		return ;
	}
	int mid = (start + end) / 2;

	update_sum(index, val, start, mid, 2 * pos);
	update_sum(index, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] ^ tree[2 * pos + 1];
	return ;
}

void update_range(int rs, int re, int val, int start, int end, int pos) {

	if (re<start or rs>end) {
		return ;
	}
	if (start == end) {
		tree[pos] ^= val;
		return ;
	}
	int mid = (start + end) / 2;

	update_range(rs, re, val, start, mid, 2 * pos);
	update_range(rs, re, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

//lazy propagation
void update_lazy(int l, int r, int val, int st, int end, int pos) {

	if (lazy[pos] != 0) {
		tree[pos] += (end - st + 1) * lazy[pos];
		if (st != end) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1]  += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (l > end or r < st) {
		return ;
	}

	if (l <= st and r >= end) {
		tree[pos] +=   (end - st + 1) * val;
		if (st != end) {
			lazy[2 * pos] += val;
			lazy[2 * pos + 1] += val;
		}
		lazy[pos] = 0;
		return ;
	}

	int mid = (st + end) / 2;
	update_lazy(l, r, val, st, mid, 2 * pos);
	update_lazy(l, r, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];

	return ;
}

int query(int l, int r, int st, int end, int pos) {

	if (lazy[pos] != 0) {
		tree[pos] += (end - st + 1) * lazy[pos];
		if (st != end) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (st > r or end < l) {
		return 0;
	}

	if (st >= l and end <= r) {
		return tree[pos];
	}

	int mid = (st + end) / 2;
	return query(l, r, st, mid, 2 * pos) +
	       query(l, r, mid + 1, end, 2 * pos + 1);

}


int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//int t;cin>>t;while(t--){}
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l,r;cin>>l>>r;

	//build_tree_min(0,n-1,1);

	build_tree_sum(0, n - 1, 1);

	//for (int i = 1; i < 2 * n + 2; i++) cout << tree[i] << " "; cout << endl;

	cout<<range_query_sum(l-1,r-1,0,n-1,1)<<endl;
	update_sum(1,10,0,n-1,1);
	cout<<range_query_sum(l-1,r-1,0,n-1,1)<<endl;



	return 0;
}