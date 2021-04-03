#include <iostream>
#include <vector>
#include <array>
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

// const int N = 1e8;
// vector <bool> is_prime(N);
// vector <int> prime;

// //O(log(n));
// void sieve() {
// 	is_prime[2] = true;
// 	prime.pb(2);
// 	for (int i = 3; i <= N; i += 2) {
// 		is_prime[i] = true;
// 	}
// 	for (int i = 3; i * i <= N; i += 2) {
// 		if (is_prime[i])
// 			for (int j = i * i; j <= N; j += 2 * i) {
// 				is_prime[j] = false;
// 			}
// 	}
// 	for (int i = 3; i <= N; i += 2) {
// 		if (is_prime[i])
// 			prime.pb(i);
// 	}
// }

// void prime_factor(int n) {
// 	for (int x : prime) {
// 		if (x * x > n)
// 			break;
// 		if (n % x == 0) {
// 			int cnt = 0;
// 			while (n % x == 0) {
// 				cnt++;
// 				n /= x;
// 			}
// 			cout << x << "^" << cnt << " ";
// 		}
// 	}
// 	if (n > 1) {
// 		cout << n << "^" << 1 << " ";
// 	}
// }

// //O(sqrt(n));
// void prime_factor(int n) {
// 	for (int i = 2; i * i <= n; i++) {
// 		if (n % i == 0) {
// 			int cnt = 0;
// 			while (n % i == 0) {
// 				cnt++;
// 				n /= i;
// 			}
// 			cout << i << "^" << cnt << " ";
// 		}
// 	}
// 	if (n > 1) {
// 		cout << n << "^" << 1 << " ";
// 	}
// }

//O(sqrt(n)) - a little optimization;
// void prime_factor(int n) {

// 	int cnt = 0;
// 	if (n % 2 == 0) {
// 		while (n % 2 == 0) {
// 			cnt++;
// 			n /= 2;
// 		}
// 		cout << 2 << "^" << cnt << " ";
// 	}

// 	for (int i = 3; i * i <= n; i += 2) {
// 		if (n % i == 0) {
// 			int cnt = 0;
// 			while (n % i == 0) {
// 				cnt++;
// 				n /= i;
// 			}
// 			cout << i << "^" << cnt << " ";
// 		}
// 	}
// 	if (n > 1) {
// 		cout << n << "^" << 1 << " ";
// 	}
// }

//
void prime_factor(int n) {

	for (int d : {2, 3, 5}) {
		if (n % d == 0) {
			int cnt = 0;
			while (n % d == 0) {
				cnt++;
				n /= d;
			}
			cout << d << "^" << cnt << " ";
		}
	}
	//how much we have to skip ;)
	static array<int, 8> skip = {4, 2, 4, 2, 4, 6, 2, 6};

	int i = 0;
	for (int d = 7; d * d <= n; d += skip[i++]) {
		if (n % d == 0) {
			int cnt = 0;
			while (n % d == 0) {
				cnt++;
				n /= d;
			}
			cout << d << "^" << cnt << " ";
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
		cout << n << "^" << 1 << " ";
}

void solve() {

		int n; cin >> n;
		prime_factor(n);
		cout << endl;

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

	//sieve();

	//int t; cin >> t; while (t--)
	solve();

	return 0;
}