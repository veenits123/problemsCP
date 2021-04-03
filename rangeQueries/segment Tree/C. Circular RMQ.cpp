#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define pb push_back
#define endl '\n'

const int N = 2e6 + 10;
int a[N];
int tree[4 * N];
int lazy[4 * N];

void build(int start, int end, int pos) {
	if (start > end) return ;

	if (start == end) {
		tree[pos] = a[start];
		return ;
	}
	int mid = (start + end) / 2;

	build(start, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);

	tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

//lazy propagation
void update(int l, int r, int val, int st, int end, int pos) {

	if (lazy[pos]) {
		tree[pos] += lazy[pos];
		if (st != end) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1]  += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (l > end or r < st || st > end) {
		return ;
	}

	if (l <= st and r >= end) {
		tree[pos] += val;
		if (st != end) {
			lazy[2 * pos] += val;
			lazy[2 * pos + 1] += val;
		}
		//lazy[pos] = 0;
		return ;
	}

	int mid = (st + end) / 2;
	update(l, r, val, st, mid, 2 * pos);
	update(l, r, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = min(tree[2 * pos] , tree[2 * pos + 1]);

	return ;
}

int query(int l, int r, int st, int end, int pos) {

	if (lazy[pos] != 0) {
		tree[pos] += lazy[pos];
		if (st != end) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (st > r or end < l || st > end) {
		return INT_MAX;
	}

	if (st >= l and end <= r) {
		return tree[pos];
	}

	int mid = (st + end) / 2;
	return min(query(l, r, st, mid, 2 * pos) ,
	           query(l, r, mid + 1, end, 2 * pos + 1));

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
	memset(lazy, 0, sizeof(lazy));
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, n , 1);
	int q; cin >> q;
	cin.ignore();
	while (q--) {
		string s;
		getline(cin, s);

		vector <string> vv;
		stringstream str(s);
		string temp;
		while (getline(str, temp, ' ')) {
			vv.pb(temp);
		}

		if (vv.size() == 3) {
			int l, r, v;
			l = stoi(vv[0]); l++;
			r = stoi(vv[1]); r++;
			v = stoi(vv[2]);
			//cout<<l<<r<<v<<endl;
			if (l <= r)
				update(l, r, v, 1, n , 1);
			else {
				update(1, r, v, 1, n , 1);
				update(l, n , v, 1, n , 1);
			}

		}
		else {
			int l, r;
			l = stoi(vv[0]); l++;
			r = stoi(vv[1]); r++;
			//cout<<l<<r<<endl;
			if (l <= r) {
				cout << query(l, r, 1, n , 1) << endl;
			}

			else {
				int ans = min(query(1, r, 1, n , 1), query(l, n , 1, n, 1));
				cout << ans << endl;
			}

		}
	}


	return 0;
}