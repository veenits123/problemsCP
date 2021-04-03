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

void solve() {

	int n; cin >> n;
	char a[n + 1][n + 1];
	REP(i, 1, n)
	REP(j, 1, n)
	cin >> a[i][j];

	int dp[n + 1][n + 1];

	if (a[n][n] == '.')
		dp[n][n] = 1;
	else
		dp[n][n] = 0;

	REV(i, n - 1, 1) {
		if (a[n][i] == '.')
			dp[n][i] = dp[n][i + 1];
		else
			dp[n][i] = 0;
		if (a[i][n] == '.')
			dp[i][n] = dp[i + 1][n];
		else
			dp[i][n] = 0;
	}
	REV(i, n - 1, 1) {
		REV(j, n - 1, 1) {
			if (a[i][j] == '.')
				dp[i][j] = dp[i + 1][j] % mod + dp[i][j + 1] % mod;
			else
				dp[i][j] = 0;
		}
	}
	cout << dp[1][1] % mod << endl;

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