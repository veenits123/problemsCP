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

int mat[3][3];
int identity[3][3];

void init() {
	mat[0][0] = 0;
	mat[0][1] = mat[1][0] = mat[1][1] = 1;

	identity[0][1] = identity[1][0] = 0;
	identity[1][1] = identity[0][0] = 1;
}

void mul(int a[3][3], int b[3][3]) {
	int temp[3][3];
	REP(i, 0, 1) {
		REP(j, 0, 1) {
			temp[i][j] = 0;
			REP(k, 0, 1) {
				temp[i][j] = (temp[i][j] % mod + (a[i][k] * b[k][j])) % mod;
			}
		}
	}
	REP(i, 0, 1) {
		REP(j, 0, 1) {
			a[i][j] = temp[i][j] % mod;
		}
	}
}

void binpow(int n) {

	while (n > 0) {

		if (n & 1)
			mul(identity, mat);

		n >>= 1;
		mul(mat, mat);
	}
	REP(i, 0, 1) {
		REP(j, 0, 1) {
			mat[i][j] = identity[i][j] % mod;
		}
	}
}

void solve() {

	init();

	int n; cin >> n;

	binpow(n - 1);

	int a = 1, b = 2;

	int ans = a * mat[0][0] % mod + b * mat[1][0] % mod;

	cout << ans % mod << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}