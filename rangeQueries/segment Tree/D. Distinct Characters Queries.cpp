#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

const int N = 1e5 + 5;
int a[N];
int tree[4 * N];

void build(int st, int end, int pos) {
	if (st > end) return ;
	if (st == end) {
		tree[pos] = 1 << a[st];
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);
	tree[pos] = tree[2 * pos] | tree[2 * pos + 1];
	return ;
}

void update(int index, int val, int start, int end, int pos) {

	if (index<start or index>end || start > end) {
		return ;
	}
	if (start == end) {
		tree[pos] = 1 << val;
		return ;
	}
	int mid = (start + end) / 2;

	update(index, val, start, mid, 2 * pos);
	update(index, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] | tree[2 * pos + 1];
	return ;
}

int query(int l, int r, int st, int end, int pos) {

	if (st > r or end < l || st > end) {
		return 0;
	}

	if (st >= l and end <= r) {
		return tree[pos];
	}

	int mid = (st + end) / 2;
	return query(l, r, st, mid, 2 * pos) |
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
	// string s; cin >> s;
	// vector <set<int>> a(26);
	// for (int i = 0; i < s.size(); i++) {
	// 	a[s[i] - 'a'].insert(i);
	// }
	// int q; cin >> q;
	// while (q--) {
	// 	int x; cin >> x;
	// 	if (x == 1) {
	// 		int ind; cin >> ind;
	// 		char c; cin >> c;
	// 		ind--;
	// 		a[s[ind] - 'a'].erase(ind);
	// 		s[ind] = c;
	// 		a[s[ind] - 'a'].insert(ind);

	// 	}
	// 	else {
	// 		int l, r; cin >> l >> r;
	// 		l--, r--;
	// 		int ans = 0;
	// 		for (int i = 0; i < 26; i++) {
	// 			auto x = a[i].lower_bound(l);
	// 			if (x != a[i].end() && *x <= r) {
	// 				ans++;
	// 			}
	// 		}
	// 		cout << ans << endl;

	// 	}
	// }

	string s; cin >> s;
	int n = s.size();
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - 'a';
	}
	build(1, n, 1);
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		if (x == 1) {
			int ind; char c; cin >> ind >> c;
			update(ind, c - 'a', 1, n, 1);
		}
		else {
			int l, r; cin >> l >> r;
			int ans = query(l, r, 1, n, 1) ;
			ans = __builtin_popcount(ans);
			cout << ans << endl;
		}
	}


	return 0;
}