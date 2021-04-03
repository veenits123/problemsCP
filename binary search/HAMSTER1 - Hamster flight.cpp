#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define sp(x,y) fixed<<setprecision(y)<<x
#define pi 3.141592653
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

double point(double angle, double u, double k1, double k2) {
	double h = u * u * sin(angle) * sin(angle) * 0.5 * 0.1;
	double d = u * u * 2.0 * sin(angle) * cos(angle) * 0.1;
	return d * k1 + h * k2;
}

void solve() {

	double u, k1, k2; cin >> u >> k1 >> k2;
	double height = 0.0, range = 0.0;
	double angle = 0.0;
	double ans = 0.0;
	double temp_ans = 0.0;

	if (k1 == 0) {//maximum height at 90-degree;
		angle = pi / 2.0;
		ans = point(angle, u, k1, k2);
		cout << sp(angle, 3) << " " << sp(ans, 3) << endl;
		temp_ans = ans;
		return ;
	}
	if (k2 == 0) {//maximum range at 45-degree;
		angle = pi / 4.0;
		ans = point(angle, u, k1, k2);
		cout << sp(angle, 3) << " " << sp(ans, 3) << endl;
		temp_ans = ans;
		return ;
	}
	angle = atan(-4 * k1 / k2);
	if (angle <= 0)
		angle += pi;
	angle /= 2.0;

	if (temp_ans > ans)
		ans = temp_ans;

	ans = point(angle, u, k1, k2);
	cout << sp(angle, 3) << " " << sp(ans, 3) << endl;

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