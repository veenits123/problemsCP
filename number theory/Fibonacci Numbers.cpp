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

const int N = 3;
int mat[N][N];
int identity[N][N];

void init() {
	mat[1][1] = 0;
	mat[1][2] = mat[2][1] = mat[2][2] = 1;

	identity[1][1] = identity[2][2] = 1;
	identity[1][2] = identity[2][1] = 0;
}

void multiply(int a[N][N], int b[N][N]) {
	int temp[N][N];
	REP(i, 1, 2) {
		REP(j, 1, 2) {
			temp[i][j] = 0;
			REP(k, 1, 2) {
				temp[i][j] = temp[i][j] % mod + ((a[i][k] % mod) * (b[k][j] % mod)) % mod;
			}
		}
	}
	REP(i, 1, 2) {
		REP(j, 1, 2) {
			a[i][j] = temp[i][j] % mod;
		}
	}
}

void binpow(int k) {
	while (k) {
		if (k & 1) {
			multiply(identity, mat);
			REP(i, 1, 2) {
				REP(j, 1, 2) {
					identity[i][j] = identity[i][j] % mod;
				}
			}
			k--;
		}
		k >>= 1;
		multiply(mat, mat);
		REP(i, 1, 2) {
			REP(j, 1, 2) {
				mat[i][j] = mat[i][j] % mod;
			}
		}
	}
	REP(i, 1, 2) {
		REP(j, 1, 2) {
			mat[i][j] = identity[i][j] % mod;
		}
	}
}

void solve() {

	init();

	int a, b, n; cin >> n;
	a = 0, b = 1;

	if (n == 0) {
		cout << 0 << endl;
		return ;
	}

	if (n <= 2)
		cout << b << endl;

	else {
		binpow(n - 1);

		int ans = ((a % mod * mat[1][2] % mod) + (b % mod * mat[2][2] % mod)) % mod;
		cout << ans % mod << endl;
	}

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//int t; cin >> t; while (t--)
	solve();

	return 0;
}