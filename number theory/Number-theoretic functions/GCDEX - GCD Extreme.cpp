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

const int N = 1e6 + 5;
int phi[N];
int S[N];
int G[N];

void etf() {
	REP(i, 1, N)
	phi[i] = i;

	REP(i, 2, N) {
		if (phi[i] == i)
			for (int j = i; j <= N; j += i) {
				phi[j] -= phi[j] / i;
			}
	}
}

//G(n)=G(n-1)+S(n);
//        S(n) is the summation of gcd(i,n) for i 1 to n-1;
void init() {

	REP(i, 1, N) {
		for (int j = 2 * i; j <= N; j += i) {
			S[j] += i * phi[j / i];
		}
	}

	REP(i, 1, N) {
		G[i] = G[i - 1] + S[i];
	}
}

void solve() {

	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			return ;
		cout << G[n] << endl;
	}

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

	etf();
	init();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}