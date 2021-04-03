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

// class Solution {
// public:
// 	int change(int amount, vector<int>& coins) {
// 		int n = coins.size();
// 		vector <vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
// 		return ways(coins, n, amount, dp);
// 	}
// 	int ways(vector<int>& coins, int n, int sum, vector <vector<int>> &dp) {
// 		if (sum < 0)
// 			return 0;
// 		if (sum == 0)
// 			return 1;
// 		if (n <= 0 && sum > 0)
// 			return 0;
// 		if (dp[n][sum] != -1)
// 			return dp[n][sum];
// 		int take = ways(coins, n, sum - coins[n - 1], dp);
// 		int not_take = ways(coins, n - 1, sum, dp);
// 		return dp[n][sum] = take + not_take;
// 	}
// };

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
		for (int i = 0; i <= n; i++)
			dp[i][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= amount; j++) {
				if (j >= coins[i - 1]) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[n][amount];
	}
};

//DP (space : O(amount));
// class Solution {
// public:
// 	int change(int amount, vector<int>& coins) {
// 		int n = coins.size();
// 		int dp[amount + 1];
// 		fill(dp, dp + amount + 1, 0);
// 		dp[0] = 1;

// 		for (int i = 1; i <= n; i++) {
// 			for (int j = 1; j <= amount; j++) {
// 				if (j - coins[i - 1] >= 0)
// 					dp[j] += dp[j - coins[i - 1]];
// 			}
// 		}
// 		return dp[amount];
// 	}
// };

void solve() {

	int n, sum; cin >> n >> sum;
	vi coins(n);

	REP(i, 0, n - 1) cin >> coins[i];

	cout << Solution().change(sum, coins);

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