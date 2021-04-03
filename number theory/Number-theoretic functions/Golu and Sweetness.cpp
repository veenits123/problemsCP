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

#define int long long
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
int phi[N];

void etf() {
	REP(i, 1, N)
	phi[i] = i;

	REP(i, 2, N) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}
}

void solve() {

	int n, q; cin >> n >> q;
	int a[n + 1];
	int prefix[n + 1] = {0};
	REP(i, 1, n) {
		cin >> a[i];
		if (a[i] == 3 || a[i] == 4 || a[i] == 6)
			prefix[i] = 1;
	}
	REP(i, 1, n)
	prefix[i] += prefix[i - 1];

	while (q--) {
		int l, r; cin >> l >> r;
		cout << prefix[r] - prefix[l - 1] << endl;
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

	etf();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}