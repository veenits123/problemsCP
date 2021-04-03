#include <iostream>

using namespace std;

#define int long long int
#define endl '\n'

const int N = 1e5 + 5;
int a[N];
int table[N][27];
int tree[27][4 * N];
int lazy[27][4 * N];

void build(int st, int end, int row, int pos) {
	if (st > end) return ;
	if (st == end) {
		tree[row][pos] = table[st][row];
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, row, 2 * pos);
	build(mid + 1, end, row, 2 * pos + 1);
	tree[row][pos] = tree[row][2 * pos] + tree[row][2 * pos + 1];
	return ;
}

void update(int l, int r, int st, int end, int row, int pos) {
	if (lazy[row][pos]) {
		tree[row][pos] = (end - st + 1) - tree[row][pos];
		if (st != end) {
			lazy[row][2 * pos] ^= 1;
			lazy[row][2 * pos + 1] ^= 1;
		}
		lazy[row][pos] = 0;
	}
	if (st > end || l > end || st > r) return ;
	if (st >= l && r >= end) {
		tree[row][pos] = (end - st + 1) - tree[row][pos];
		if (st != end) {
			lazy[row][2 * pos] ^= 1;
			lazy[row][2 * pos + 1] ^= 1;
		}
		lazy[row][pos] = 0;
		return ;
	}
	int mid = (st + end) / 2;
	update(l, r, st, mid, row, 2 * pos);
	update(l, r, mid + 1, end, row, 2 * pos + 1);
	tree[row][pos] = tree[row][2 * pos] + tree[row][2 * pos + 1];
	return ;
}


int query(int l, int r, int st, int end, int row, int pos) {
	if (lazy[row][pos]) {
		tree[row][pos] = (end - st + 1) - tree[row][pos];
		if (st != end) {
			lazy[row][2 * pos] ^= 1;
			lazy[row][2 * pos + 1] ^= 1;
		}
		lazy[row][pos] = 0;
	}
	if (st > end || st > r || l > end) return 0;
	if (st >= l && r >= end) return tree[row][pos];
	int mid = (st + end) / 2;
	return query(l, r, st, mid, row, 2 * pos) + query(l, r, mid + 1, end, row, 2 * pos + 1);
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 27; j++) {
			if (a[i] & (1 << j)) table[i][j] = 1;
			else table[i][j] = 0;
		}
	}
	//cout<<"djndj";
	for (int i = 0; i < 27; i++) {
		build(0, n - 1, i, 1);
	}

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		if (x == 1) {
			int l, r; cin >> l >> r;
			l--; r--;
			int ans = 0;
			for (int i = 0; i < 27; i++) {
				ans += (1 << i) * query(l, r, 0, n - 1, i, 1);
			}
			cout << ans << endl;
		}
		else {
			int l, r, val; cin >> l >> r >> val;
			l--; r--;
			for (int i = 0; i < 27; i++) {
				if (val & (1 << i))
					update(l, r, 0, n - 1, i, 1);
			}
		}
	}
	//cout<<pow(2,20);


	return 0;
}