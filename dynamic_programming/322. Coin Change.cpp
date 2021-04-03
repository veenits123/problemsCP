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
// 	int coinChange(vector<int>& coins, int amount) {
// 		int n = coins.size();
// 		return count(coins, n, amount);
// 	}
// 	int count(vector <int> & coins, int n, int sum) {
// 		if (sum == 0)
// 			return 0;
// 		int ans = 1e9;
// 		for (int i = 0; i < n; i++) {
// 			if (sum >= coins[i]) {
// 				int temp = count(coins, n, sum - coins[i]);
// 				if (temp + 1 < ans && temp >= 0 && temp != 1e9)
// 					ans = temp + 1;
// 			}
// 		}
// 		return (ans == 1e9) ? -1 : ans;
// 	}
// };

//memoized ;)
// class Solution {
// public:
// 	int coinChange(vector<int>& coins, int amount) {
// 		int n = coins.size();
// 		vector <int> dp(amount + 1, 0);
// 		return count(coins, n, amount, dp);
// 	}
// 	int count(vector <int> & coins, int n, int sum, vector<int> &dp) {
// 		if (sum == 0)
// 			return 0;
// 		if (sum < 0)
// 			return -1;
// 		if (dp[sum])
// 			return dp[sum];
// 		int ans = 1e9;
// 		for (int i = 0; i < n; i++) {
// 			if (sum >= coins[i]) {
// 				int temp = count(coins, n, sum - coins[i], dp);
// 				if (temp + 1 < ans && temp >= 0)
// 					ans = temp + 1;
// 			}
// 		}
// 		return dp[sum] = (ans == 1e9) ? -1 : ans;
// 	}
// };

class Solution {
public:
	int inf = 1e9;
	int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		int dp[n + 1][amount + 1];
		for (int i = 1; i <= n; i++) {
			dp[i][0] = 0;
		}
		for (int j = 0; j <= amount; j++) {
			dp[0][j] = inf;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= amount; j++) {
				if (j >= coins[i - 1]) {
					dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return (dp[n][amount] == 1e9) ? -1 : dp[n][amount];
	}
};

void solve() {

	int n; cin >> n;
	int s; cin >> s;
	vi v;
	REP(i, 1, n) {
		int x; cin >> x;
		v.pb(x);
	}

	cout << Solution().coinChange(v, s) << endl;

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