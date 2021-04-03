#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e6 + 7;
int tree[4 * N];
int a[N];
int lazy[4 * N];
int q, n, x, l, r;

//lazy propagation
void update_lazy(int l, int r, int st, int end, int pos) {
	if (st > end) return ;
	if (lazy[pos] != 0) {
		tree[pos] = (end - st + 1 - tree[pos]);
		if (st != end) {
			lazy[2 * pos ] = 1 - lazy[2 * pos];
			lazy[2 * pos + 1]  = 1 - lazy[2 * pos + 1];
		}
		lazy[pos] = 0;
	}

	if (l > end or r < st) {
		return ;
	}

	if (l <= st and r >= end) {
		tree[pos] = (end - st + 1 - tree[pos]);
		if (st != end) {
			lazy[2 * pos ] = 1 - lazy[2 * pos];
			lazy[2 * pos + 1]  = 1 - lazy[2 * pos + 1];
		}
		//lazy[pos] = 0;
		return ;
	}

	int mid = (st + end) / 2;
	update_lazy(l, r, st, mid, 2 * pos);
	update_lazy(l, r, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];

	return ;
}

int query(int l, int r, int st, int end, int pos) {
	if (st > end) return 0;
	if (lazy[pos] != 0) {
		tree[pos] = (end - st + 1 - tree[pos]);
		if (st != end) {
			lazy[2 * pos ] = 1 - lazy[2 * pos];
			lazy[2 * pos + 1]  = 1 - lazy[2 * pos + 1];
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
	cin >> n >> q;
	memset(lazy, 0, sizeof(lazy));
	memset(tree, 0, sizeof(tree));

	while (q--) {
		//for(int i=0;i<2*n;i++) cout<<tree[i]<<" ";cout<<endl;
		cin >> x;
		if (x == 1) {
			cin >> l >> r;
			cout << query(l, r, 0, n - 1, 1) << endl;
		}
		else {
			cin >> l >> r;
			update_lazy(l, r, 0, n - 1, 1);
		}
	}


	return 0;
}