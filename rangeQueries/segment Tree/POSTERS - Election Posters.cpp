#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e5 + 5;
int tree[4 * N];
int lazy[4 * N];

void update(int l, int r, int val, int st, int end, int pos) {

	if (lazy[pos]) {
		tree[pos] = lazy[pos];
		if (st != end) {
			lazy[2 * pos] = lazy[pos];
			lazy[2 * pos + 1] = lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (st > end || st > r || l > end) return ;

	if (st >= l && r >= end) {
		tree[pos] = val;
		if (st != end) {
			lazy[2 * pos] = val;
			lazy[2 * pos + 1] = val;
		}
		lazy[pos] = 0;
		return ;
	}

	int mid = (st + end) / 2;
	update(l, r, val, st, mid, 2 * pos);
	update(l, r, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = val;

	return ;
}

int query(int l, int r, int st, int end, int pos) {

	if (lazy[pos]) {
		tree[pos] = lazy[pos];
		if (st != end) {
			lazy[2 * pos] = lazy[pos];
			lazy[2 * pos + 1] = lazy[pos];
		}
		lazy[pos] = 0;
	}
	if (st > end || l > end || st > r) return -1;

	if (st >= l && r >= end) return tree[pos];

	int mid = (st + end) / 2;
	return max(query(l, r, st, mid, 2 * pos), query(l, r, mid + 1, end, 2 * pos + 1));
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t; while (t--) {

		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));

		map <int, int> compress;
		P points[N];

		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int l, r; cin >> l >> r;
			points[i].F = l;
			points[i].S = r;
			compress[points[i].F] = 1;
			compress[points[i].S] = 1;
		}

		// for(auto x:compress){
		// 	cout<<x.F<<" "<<x.S<<endl;
		// }

		int p = 0;
		for (auto &x : compress) {
			x.S = p++;
		}

		// for(auto x:compress){
		// 	cout<<x.F<<" "<<x.S<<endl;
		// }

		for (int i = 0; i < n; i++) {
			update(compress[points[i].F], compress[points[i].S], i + 1, 0, N - 1, 1);
		}

		set <int> s;

		for (int i = 0; i < N; i++) {
			s.insert(query(i, i, 0, N - 1, 1));
		}

		int ans = s.size();

		if (s.find(0) != s.end()) ans--;
		//for(auto x:s) cout<<x<<" ";
		
		cout << ans << endl;
	}


	return 0;
}