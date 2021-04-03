#include <iostream>
#include <map>
#include <climits>

using namespace std;

#define int long long int
#define F first
#define S second
#define endl '\n'

const int N = 2e5 + 5;
int a[N];
int tree[4 * N];

map <int, int> compress;
pair <int, int> times[N], qq[N];

void build(int start, int end, int pos) {
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

	if (q_low > end or q_high < start) {
		return INT_MIN;
	}

	if (q_low <= start and q_high >= end) {
		return tree[pos];
	}

	int mid = (start + end) / 2;
	int left = query(q_low, q_high, start, mid, 2 * pos);
	int right = query(q_low, q_high, mid + 1, end, 2 * pos + 1);

	return max(left, right);
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
		int x, y; cin >> x >> y;
		times[i].F = x;
		times[i].S = y;
		compress[x] = 1;
		compress[y] = 1;
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		qq[i].F = l;
		qq[i].S = r;
		compress[l] = 1;
		compress[r] = 1;
	}
	int c = 0;
	for (auto &x : compress) {
		x.S = c++;
	}
	for (int i = 0; i < n; i++) {
		a[compress[times[i].F]]++;
		a[compress[times[i].S] + 1]--;
	}
	for (int i = 0; i < N; i++) {
		a[i] += a[i - 1];
	}
	build(0, N - 1, 1);
	for (int i = 0; i < q; i++) {
		cout << query(compress[qq[i].F], compress[qq[i].S], 0, N - 1, 1) << endl;
	}


	return 0;
}