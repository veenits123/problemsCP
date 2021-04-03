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

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		int n = A.size();
		int m = A[0].size();

		int dp[n][m];
		for (int j = 0; j < m; j++)
			dp[n - 1][j] = A[n - 1][j];

		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {

				dp[i][j] = A[i][j];

				int mn = dp[i + 1][j];

				if ((j + 1) < m)
					mn = min(mn, dp[i + 1][j + 1]);
				if ((j - 1) >= 0)
					mn = min(mn, dp[i + 1][j - 1]);

				dp[i][j] += mn;
			}
		}
		int ans = (int)1e9;
		for (int j = 0; j < m; j++) {
			ans = min(ans, dp[0][j]);
		}
		return ans;
	}
};

void solve() {

	int n, m; cin >> n >> m;
	vector <vector<int>> a(n, vector <int> (m));

	REP(i, 0, n - 1)
	REP(j, 0, m - 1)
	cin >> a[i][j];

	cout << Solution().minFallingPathSum(a) << endl;

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