#include <iostream>
#include <algorithm>
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
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 5e4 + 5;
int n;
pair<P, int> a[N];
int vol;
double cnt;

bool check(double mid) {
	cnt = 0.0;
	for (int i = 0; i < n; i++) {
		int x = a[i].F.F + a[i].F.S;

		if (mid >= x)//mid-b>h;
			cnt += a[i].S;

		else if (mid < x && mid > a[i].F.F)//mid-b<h;
			cnt += (mid - a[i].F.F) * a[i].S / a[i].F.S;

		//cout << a[i].F.F << " " << a[i].F.S << endl;
		//cout << cnt << endl;
	}
	//cout << cnt << endl;
	if (cnt >= vol)
		return false;
	return true;
}

double binary_search() {

	double low = 0.0;
	double high = 1040000.0;

	for (int i = 0; i < 100; i++) {
		double mid = low + (high - low) / 2.0;
		if (check(mid)) {
			low = mid;
			//cout << "hiii";
		}
		else
			high = mid;
		//cout << low << " " << high << endl;
		//cout << mid << " " << cnt << endl;
	}
	return low;
}

void solve() {
	cin >> n;
	vol = 0;
	double sum = 0.0;

	for (int i = 0; i < n; i++) {
		int b, h, w, d; cin >> b >> h >> w >> d;
		a[i] = {{b, h}, w * d * h};
		sum += w * d * h;
	}
	cnt = 0;
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i].F.F << " " << a[i].F.S << " " << a[i].S << endl;
	// }
	//cout << sum << endl;
	cin >> vol;

	if (vol > sum)
		cout << "OVERFLOW" << endl;

	else
		cout << sp(binary_search(), 2) << endl;

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