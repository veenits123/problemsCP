#include <iostream>
#include <cstring>

using namespace std;

#define int long long int
#define endl '\n'

const int N = 1e5 + 5;
int a[N];
int tree[4 * N];
int mx[4 * N];

void push_up(int pos) {
	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	mx[pos] = max(mx[2 * pos], mx[2 * pos + 1]);
}

void build(int st, int end, int pos) {
	if (st > end) return ;
	if (st == end) {
		tree[pos] = a[st];
		mx[pos] = a[st];
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);
	push_up(pos);
	return ;
}

void update(int l, int r, int val, int st, int end, int pos) {
	if (mx[pos] < val) return ;
	if (st > end || l > end || st > r) return ;

	if (st == end) {
		tree[pos] %= val;
		mx[pos] = tree[pos];
		return ;
	}
	int mid = (st + end) / 2;
	update(l, r, val, st, mid, 2 * pos);
	update(l, r, val, mid + 1, end, 2 * pos + 1);
	push_up(pos);
	return ;
}

void assign(int ind, int val, int st, int end, int pos) {
	if (ind > end || st > ind || st > end) return ;
	if (st == end) {
		tree[pos] = val;
		mx[pos] = val;
		return ;
	}
	int mid = (st + end) / 2;
	assign(ind, val, st, mid, 2 * pos);
	assign(ind, val, mid + 1, end, 2 * pos + 1);
	push_up(pos);
	return ;
}

int query(int l, int r, int st, int end, int pos) {
	if (st > end || l > end || st > r) return 0;
	if (st >= l && r >= end) return tree[pos];
	int mid = (st + end) / 2;
	return query(l, r, st, mid, 2 * pos) + query(l, r, mid + 1, end, 2 * pos + 1);
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
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, n, 1);
	while (q--) {
		int x; cin >> x;
		if (x == 1) {
			int l, r; cin >> l >> r;
			cout << query(l, r, 1, n, 1) << endl;
		}
		else if (x == 2) {
			int l, r, v; cin >> l >> r >> v;
			update(l, r, v, 1, n, 1);
		}
		else {
			int ind, val; cin >> ind >> val;
			assign(ind, val, 1, n, 1);
		}
	}


	return 0;
}