#include <iostream>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e6 + 5;
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

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
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
	int n, q; cin >> n >> q;
	cout<<"djdj";

	//build_tree_sum(0, n - 1, 1);

	while (q--) {
		string s; cin >> s;
		if (s == "find") {
			int l, r; cin >> l >> r;
			cout << range_query_sum(l - 1, r - 1, 0, n - 1, 1) << endl;
		}
		else {
			int p, f; cin >> p >> f;
			update_sum(p - 1, f, 0, n - 1, 1);
		}
	}
	return 0;
}