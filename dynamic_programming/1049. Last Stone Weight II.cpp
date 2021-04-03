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
	int lastStoneWeightII(vector<int>& stones) {
		int n = stones.size();
		int range = 0;
		for (int i = 0; i < n; i++)
			range += stones[i];
		return min_diff_subsum(stones, n, range);
	}
	int min_diff_subsum(vector <int> &a, int n, int sum) {
		bool dp[n + 1][(sum + 1) / 2 + 1];
		for (int i = 0; i <= n; i++)
			dp[i][0] = true;
		for (int j = 1; j <= (sum + 1) / 2; j++)
			dp[0][j] = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= (sum + 1) / 2; j++) {
				if (a[i - 1] > j)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
			}
		}
		int ans = 100000;
		for (int i = sum / 2; i >= 0; i--) {
			if (dp[n][i]) {
				ans = min(ans, sum - 2 * i);
				break;
			}
		}
		return ans;
	}
};

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];
	cout << Solution().lastStoneWeightII(a) << endl;

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