#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;
int a[N];
int block[1005];
int BLK;
int n;

void preprocess(int arr[], int m) {
	int sz = ceil(sqrt(m));
	int ptr = -1;
	REP(i, 0, m - 1) {
		if (i % sz == 0) {
			ptr++;
			block[ptr] = arr[i];
		}
		block[ptr] = min(block[ptr], arr[i]);
	}
}

int query(int l, int r) {
	int lb = l / BLK;
	int rb = r / BLK;
	int ans = (int)1e18;

	if (lb == rb) {
		REP(i, l, r) {
			ans = min(ans, a[i]);
		}
	}
	else {
		REP(i, l, BLK * (lb + 1) - 1) {
			ans = min(ans, a[i]);
		}
		REP(i, (lb + 1), rb - 1) {
			ans = min(ans, block[i]);
		}
		REP(i, BLK * rb, r) {
			ans = min(ans, a[i]);
		}
	}
	return ans;
}

void solve() {

	cin >> n;

	BLK = ceil(sqrt(n));

	REP(i, 0, n - 1) {
		cin >> a[i];
	}
	preprocess(a, n);

	// REP(i, 0, n - 1)
	// cout << block[i] << " ";

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << query(a, b) << endl;
	}

	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}