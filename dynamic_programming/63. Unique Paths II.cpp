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
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();

		long long dp[n + 1][m + 1];

		if (obstacleGrid[n - 1][m - 1] == 1 || obstacleGrid[0][0] == 1)
			return 0;

		dp[n][m] = 1;

		for (int i = n - 1; i >= 1; i--) {
			if (obstacleGrid[i - 1][m - 1] == 1)
				dp[i][m] = 0;
			else
				dp[i][m] = dp[i+1][m];
		}
		for (int j = m - 1; j >= 1; j--) {
			if (obstacleGrid[n - 1][j - 1] == 1)
				dp[n][j] = 0;
			else
				dp[n][j] = dp[n][j+1];
		}

		for (int i = n - 1; i >= 1; i--) {
			for (int j = m - 1; j >= 1; j--) {
				if (obstacleGrid[i - 1][j - 1] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
			}
		}
		return dp[1][1];
	}
};

void solve() {

	int n, m; cin >> n >> m;
	vector <vi> a(n, vi (m));

	REP(i, 0, n - 1)
	REP(j, 0, m - 1)
	cin >> a[i][j];

	cout << Solution().uniquePathsWithObstacles(a) << endl;

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
