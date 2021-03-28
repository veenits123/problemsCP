#include <iostream>
using namespace std;

#define int long long int
#define endl '\n'

int temp_z = 0;

int func(int x, int y, int z) {
  return (x & z) * (y & z);
}

int prefix(int l, int r) {
  int k = 0;
  for (int i = 42; i >= 0; i--) {
    if (l & (1LL << i) == r & (1LL << i)) {
      if (r & (1LL << i)) {
        temp_z |= (1LL << i);
      }
    }
    else {
      k = i;
      break;
    }
  }
  return k;
}

void solve() {

  int x, y, l, r; cin >> x >> y >> l >> r;
  int x_o_y = x | y;
  int mx = func(x, y, l);
  int k = prefix(l, r);
  int ans = l;
  int t_z = temp_z;

  //SUBTASK-2;
  for (int i = k; i >= 0; i--) {
    //initializing container with prefixed value
    t_z = temp_z;
    //adding R
    for (int j = k; j >= i; j--) {
      if (r & (1LL << j)) {
        t_z |= (1LL << j);
      }
    }
    //setting R[i]=0 bcz Z<R;
    t_z &= (~(1LL << i));
    //adding x|y
    for (int j = i - 1; j >= 0; j--) {
      if (x_o_y & (1LL << j)) {
        t_z |= (1LL << j);
      }
    }
    //optimising Z
    if (t_z <= r && t_z >= l) {
      if (func(x, y, t_z) > mx) {
        mx = func(x, y, t_z);
        ans = t_z;
      }
      if (func(x, y, t_z) == mx) {
        ans = min(ans, t_z);
      }
    }
  }//SUBTASK-2;

  for (int i = k; i >= 0; i--) {
    //initializing container with prefixed value
    t_z = temp_z;
    //adding L
    for (int j = k; j >= i; j--) {
      if (l & (1LL << j)) {
        t_z |= (1LL << j);
      }
    }
    //making L[i]=1 bcz Z>L;
    t_z |= ((1LL << i));
    //adding x|y
    for (int j = i - 1; j >= 0; j--) {
      if (x_o_y & (1LL << j)) {
        t_z |= (1LL << j);
      }
    }
    //optimising Z
    if (t_z <= r && t_z >= l) {
      if (func(x, y, t_z) > mx) {
        mx = func(x, y, t_z);
        ans = t_z;
      }
      if (func(x, y, t_z) == mx) {
        ans = min(ans, t_z);
      }
    }
  }
  //checking for R (inclusive)
  if (func(x, y, r) > mx) {
    ans = r;
  }
  cout << ans << endl;
  return ;
}

int32_t main() {

  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  // code starts

  int t; cin >> t; while (t--) {
    solve();
  }

  return 0;
}