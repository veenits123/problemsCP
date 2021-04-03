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

#define int long long
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

const int N = 50 + 5;
int mat[N][N];
int identity[N][N];

void multiply(int a[][N], int b[][N], int n) {
	int temp[n + 1][n + 1];
	REP(i, 1, n) {
		REP(j, 1, n) {
			temp[i][j] = 0;
			REP(k, 1, n) {
				temp[i][j] = temp[i][j] % mod + ((a[i][k] % mod) * (b[k][j] % mod)) % mod;
			}
		}
	}
	REP(i, 1, n) {
		REP(j, 1, n) {
			a[i][j] = temp[i][j] % mod;
		}
	}
}

void binpow(int a[][N], int n, int k) {
	REP(i, 1, n) {
		REP(j, 1, n) {
			if (i == j)
				identity[i][j] = 1;
			else
				identity[i][j] = 0;
		}
	}
	while (k) {
		if (k & 1) {
			multiply(identity, a, n);
			REP(i, 1, n) {
				REP(j, 1, n) {
					identity[i][j] = identity[i][j] % mod;
				}
			}
			k--;
		}
		k >>= 1;
		multiply(a, a, n);
		REP(i, 1, n) {
			REP(j, 1, n) {
				a[i][j] = a[i][j] % mod;
			}
		}
	}
	REP(i, 1, n) {
		REP(j, 1, n) {
			a[i][j] = identity[i][j] % mod;
		}
	}
}

void print(int a[][N], int n) {
	REP(i, 1, n) {
		REP(j, 1, n) {
			cout << a[i][j] % mod << " ";
		}
		cout << endl;
	}
}

void solve() {

	int n, k; cin >> n >> k;
	REP(i, 1, n) {
		REP(j, 1, n) {
			cin >> mat[i][j];
		}
	}
	binpow(mat, n, k);

	print(mat, n);

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