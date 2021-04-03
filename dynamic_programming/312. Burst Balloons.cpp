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

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		vector <int> temp(n + 2);
		temp[0] = 1, temp[n + 1] = 1;
		for (int i = 1; i <= n; i++) {
			temp[i] = nums[i - 1];
		}
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
		return mcm_memo(temp, 1, n + 1, dp);
	}
	int mcm_memo(vector <int> &a, int i, int j, vector <vector<int>> &dp) {
		if (i >= j)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		dp[i][j] = 0;
		for (int k = i; k < j; k++) {
			int temp = mcm_memo(a, i, k, dp) + mcm_memo(a, k + 1, j, dp) +
			           (a[i - 1] * a[k] * a[j]);
			dp[i][j] = max(dp[i][j], temp);
		}
		return dp[i][j];
	}
};

//DP ;)
// class Solution {
// public:
// 	int maxCoins(vector<int>& nums) {
// 		nums.insert(nums.begin(), 1);
// 		nums.push_back(1);
// 		int n = nums.size();
// 		return mcm(nums);
// 	}
// 	int mcm(vector <int> & a) {
// 		int n = a.size();
// 		int dp[n][n];
// 		memset(dp, 0, sizeof(dp));
// 		for (int window = 2; window < n; window++) {
// 			for (int i = 1; i < n - window + 1; i++) {
// 				int j = i + window - 1;
// 				for (int k = i; k < j; k++) {
// 					int temp = dp[i][k] + dp[k + 1][j] +
// 					           a[i - 1] * a[k] * a[j];
// 					if (dp[i][j] < temp)
// 						dp[i][j] = temp;
// 				}
// 			}
// 		}
// 		return dp[1][n - 1];
// 	}
// };

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	cout << Solution().maxCoins(a) << endl;

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