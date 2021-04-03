#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

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

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e7+1;
int phi[N];
vector <P> ans;

bool same(int a, int b) {
	string aa = to_string(a);
	string bb = to_string(b);
	sort(all(aa));
	sort(all(bb));
	return (aa == bb);
}

void etf() {
	REP(i, 1, N)
	phi[i] = i;

	REP(i, 2, N) {
		if (phi[i] == i)
			for (int j = i; j <= N; j += i) {
				phi[j] -= phi[j] / i;
			}
	}
	REP(i, 21, N) {
		if (same(i, phi[i]))
			ans.pb({i, phi[i]});
	}
}

void solve() {

	int n; cin >> n;
	int res = -1;
	int temp = 1e9;
	for (auto x : ans) {
		if (x.F <= n) {
			if (x.F / x.S <= temp) {
				temp = x.F / x.S;
				res = x.F;
			}
		}
	}
	if (res == -1)
		cout << "No solution." << endl;
	else
		cout << res << endl;
	// for (auto x : ans)
	// 	cout << x.F << " " << x.S << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}