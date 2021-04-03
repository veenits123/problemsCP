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
	int findTargetSumWays(vector<int>& nums, int S) {
		int n = nums.size();
		int sum = 0;
		int zero = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			if (nums[i] == 0)
				zero++;
		}
		if (S > sum || (S + sum) & 1)
			return 0;
		int k = (sum + S) / 2;
		return pow(2, zero) * subset(nums, n, k);
	}
	int subset(vector<int> &a, int n, int sum) {
		int dp[n + 1][sum + 1];
		for (int i = 0; i <= n; i++)
			dp[i][0] = 1;
		for (int i = 1; i <= sum; i++)
			dp[0][i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= sum; j++) {
				if (a[i - 1] == 0)
					dp[i][j] = dp[i - 1][j];
				else if (j < a[i - 1])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
			}
		}
		return dp[n][sum];
	}
};

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];
	int s; cin >> s;
	cout << Solution().findTargetSumWays(a, s) << endl;

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