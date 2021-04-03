#include <iostream>
#include <cmath>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e7;
double fact[N];

//formula : take log on both side of f(n)=n! and g(n)=a^n;
//log(f(n))=log(n!)=log(n*(n-1)*(n-2)*...*2*1*0)=log(n)+log(n-1)+...+log(1);
//log(g(n))=log(a^n)=n*log(a);
//n must be b/w [2a,3a] only;

void fun() {
	fact[1] = log10(1);
	for (int i = 2; i <= N; i++)
		fact[i] = fact[i - 1] + log10(i);
}

void solve() {

	int a; cin >> a;

	int l = 1, r = 1e7;
	int n = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		double fn = fact[mid];
		double gn = mid * (log10(a));
		if (fn > gn) {
			r = mid - 1;
			n = mid;
		}
		else
			l = mid + 1;
	}
	cout << n << endl;

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

	fun();
	int t; cin >> t; while (t--)
		solve();

	return 0;
}