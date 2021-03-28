#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

vector <int> primes;
const int N = 100001;
int a[N] = {0};

bool is_prime(int n) {
  a[0] = 0, a[1] = 0, a[2] = 1;
  for (int i = 3; i <= n; i++) {
    if (i & 1) {
      a[i] = 1;
    }
  }
  for (int i = 3; i <= n; i++) {
    if (a[i] == 1) {
      for (int j = i * i; j <= n; j += 2 * i) {
        a[j] = 0;
      }
    }
  }
  if (a[n]) {
    return true;
  }
  else {
    return false;
  }
}

bool almost_prime(int n, int k) {
  vector <int> factors;
  int i = 0, pr = primes[i];
  while (pr * pr <= n) {
    if (n % pr == 0) {
      factors.pb(pr);
      while (n % pr == 0) {
        n = n / pr;
      }
    }
    i++;
    pr = primes[i];
  }
  if (n != 1) factors.pb(n);

  if (factors.size() == k) {
    return true;
  }
  else {
    return false;
  }
}

int32_t main() {

  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  // code starts

  //int t;cin>>t;while(t--){

  int n; cin >> n;
  if (n == 1) {
    cout << 0;
  }
  else {
    for (int i = 1; i <= n; i++) {
      if (is_prime(i)) {
        primes.pb(i);
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (almost_prime(i)) {
        ans++;
        //cout<<i<<" ";
      }
    }
    cout << ans << endl;
  }

  return 0;
}