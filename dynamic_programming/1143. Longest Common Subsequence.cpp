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
// 	int longestCommonSubsequence(string text1, string text2) {
// 		int n = text1.size(), m = text2.size();
// 		return lcs(text1, text2, n, m);
// 	}
// 	int lcs(string &a, string &b, int n, int m) {
// 		if (n == 0 || m == 0)
// 			return 0;
// 		if (a[n - 1] == b[m - 1]) {
// 			return 1 + lcs(a, b, n - 1, m - 1);
// 		}
// 		//else if (a[n - 1] != b[m - 1]) {
// 		int all_a = lcs(a, b, n, m - 1);
// 		int all_b = lcs(a, b, n - 1, m);
// 		return max(all_a, all_b);
// 		//}
// 	}
// };

//memoized ;)
// class Solution {
// public:
// 	int longestCommonSubsequence(string text1, string text2) {
// 		int n = text1.size(), m = text2.size();
// 		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
// 		return lcs(text1, text2, n, m, dp);
// 	}
// 	int lcs(string &a, string &b, int n, int m, vector<vector<int>> &dp) {
// 		if (n == 0 || m == 0)
// 			return 0;
// 		if (dp[n][m] != -1)
// 			return dp[n][m];
// 		if (a[n - 1] == b[m - 1])
// 			return dp[n][m] = 1 + lcs(a, b, n - 1, m - 1, dp);
// 		else {
// 			int all_a = lcs(a, b, n, m - 1, dp);
// 			int all_b = lcs(a, b, n - 1, m, dp);
// 			return dp[n][m] = max(all_a, all_b);
// 		}
// 	}
// };

//DP;
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size(), m = text2.size();
		int dp[n + 1][m + 1];
		for (int i = 0; i <= n; i++)
			dp[i][0] = 0;
		for (int j = 0; j <= m; j++)
			dp[0][j] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (text1[i - 1] == text2[j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[n][m];
	}
};

void solve() {

	string a, b; cin >> a >> b;
	cout << Solution().longestCommonSubsequence(a, b);

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