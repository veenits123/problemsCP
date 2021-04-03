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

//recursive;
int knapsack(int val[], int wt[], int n, int W) {
	if (W == 0 || n == 0)
		return 0;
	if (wt[n - 1] <= W) {
		int take = val[n - 1] + knapsack(val, wt, n - 1, W - wt[n - 1]);
		int not_take = knapsack(val, wt, n - 1, W);
		return max(take, not_take);
	}
	//else if (wt[n - 1] > W)
	return knapsack(val, wt, n - 1, W);
}

//memoization;
int dp[1001][1001];
int knapsack_mem(int val[], int wt[], int n, int W) {
	if (W == 0 || n == 0)
		return 0;
	if (dp[n][W] != -1)
		return dp[n][W];
	if (wt[n - 1] <= W) {
		int take = val[n - 1] + knapsack(val, wt, n - 1, W - wt[n - 1]);
		int not_take = knapsack(val, wt, n - 1, W);
		return dp[n][W] = max(take, not_take);
	}
	return dp[n][W] = knapsack(val, wt, n - 1, W);
}

int knapsack_dp(int val[], int wt[], int n, int W) {
	int dp[n + 1][W + 1];
	REP(i, 0, n) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	REP(i, 1, n) {
		REP(j, 1, W) {
			if (wt[i - 1] <= j)
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]],
				               dp[i - 1][j]);
			else if (wt[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	return dp[n][W];
}

void solve() {

	int n; cin >> n;
	int value[n], weight[n];

	REP(i, 0, n - 1) cin >> value[i];
	REP(i, 0, n - 1) cin >> weight[i];

	int W; cin >> W;

	//memset(dp, -1, sizeof(dp));

	cout << knapsack_dp(value, weight, n, W);

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