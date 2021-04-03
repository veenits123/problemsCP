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

void binpow(int a[][N], int k) {
	while (k) {
		if (k & 1) {
			multiply(identity, a);
			REP(i, 1, 2) {
				REP(j, 1, 2) {
					identity[i][j] = identity[i][j] % mod;
				}
			}
			k--;
		}
		k >>= 1;
		multiply(a, a);
		REP(i, 1, 2) {
			REP(j, 1, 2) {
				a[i][j] = a[i][j] % mod;
			}
		}
	}
	REP(i, 1, 2) {
		REP(j, 1, 2) {
			a[i][j] = identity[i][j] % mod;
		}
	}
}

int fib(int n) {
	int temp[N][N];
	temp[1][1] = temp[1][2] = temp[2][1] = 1;
	temp[2][2] = 0;
	if (n == 0)
		return 0;
	binpow(temp, n - 1);
	return temp[0][0];
}

void solve() {

	init();

	int n; cin >> n;

	if (n == 0)
		cout << 0 << endl;
	if (n == 1)
		cout << 2 << endl;
	else {
		n += 3;
		cout << fib(n) % mod << endl;
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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}