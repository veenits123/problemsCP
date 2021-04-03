#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cstring>
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
const int inf = 1e18;

int matrix_chain_multiplication(int a[], int i, int j) {

	if (i >= j)
		return 0;

	int ans = inf;

	REP(k, i, j - 1) {
		int temp = matrix_chain_multiplication(a, i, k) +
		           matrix_chain_multiplication(a, k + 1, j) +
		           (a[i - 1] * a[k] * a[j]);
		ans = min(ans, temp);
	}

	return ans;
}

//memoized ;)
int dp[101][101];
int mcm_memo(int a[], int i, int j) {
	if (i >= j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = inf;
	REP(k, i, j - 1) {
		int temp = mcm_memo(a, i, k) + mcm_memo(a, k + 1, j) +
		           (a[i - 1] * a[k] * a[j]);
		dp[i][j] = min(dp[i][j], temp);
	}
	return dp[i][j];
}

void solve() {

	memset(dp, -1, sizeof(dp));

	int n; cin >> n;
	int a[n];
	REP(i, 0, n - 1) cin >> a[i];
	cout << mcm_memo(a, 1, n - 1) << endl;

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


