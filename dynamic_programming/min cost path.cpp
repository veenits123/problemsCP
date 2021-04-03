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

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e5 + 5;
const int inf = 1e9;

void solve() {

	int n, m; cin >> n >> m;
	int a[n + 1][m + 1];
	REP(i, 1, n)
	REP(j, 1, m)
	cin >> a[i][j];

	int dp[n + 2][m + 2];

	REP(j, 1, m + 1) {
		dp[n + 1][j] = inf;
		if (j == m)
			dp[n + 1][j] = 0;
	}
	REP(i, 1, n) {
		dp[i][m + 1] = inf;
		if (i == n)
			dp[i][m + 1] = 0;
	}

	REV(j, m, 1) {
		REV(i, n, 1) {
			dp[i][j] = a[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
		}
	}

	REP(i, 1, n) {
		REP(j, 1, m)
		cout << dp[i][j] << " ";
		cout << endl;
	}
	//path;
	cout << 1 << " " << 1 << endl;
	int i = 1, j = 1;
	while (i < n && j < m) {
		if (dp[i + 1][j] > dp[i][j + 1]) {
			cout << i << " " << j + 1 << endl;
			j++;
		}
		else {
			cout << i + 1 << " " << j << endl;
			i++;
		}
	}
	cout << n << " " << m << endl;

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