#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#ifdef LOCAL
auto& operator<<(auto&, pair<auto, auto>);
auto operator<<(auto& o, auto x) -> decltype(x.end(), o) {
  o << "{";
  for (int i = 0; auto y : x) o << ", " + !i++ * 2 << y;
  return o << "}";
}
auto& operator<<(auto& o, pair<auto, auto> x) {
  return o << "(" << x.first << ", " << x.second << ")"; }
void __print(auto... x) { ((cerr << " " << x), ...) << endl; }
#define debug(x...) cerr << "[" #x "]:", __print(x)
#else
#define debug(...) 2137
#endif

#include "content/number-theory/ModInt.h"
int abs(mint x) { return x.x; }

#include "content/numerical/SolveLinear.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<mint>> a(n, vector<mint>(m));
  rep(i, 0, n) rep(j, 0, m) cin >> a[i][j].x;
  vector<mint> b(n), x(m);
  rep(i, 0, n) cin >> b[i].x;
  int r = solveLinear(a, b, x);
  if (r == -1) {
    cout << -1 << '\n';
  } else {
    cout << m - r << '\n';
    rep(i, 0, m) cout << x[i].x << " \n"[i == m - 1];
    rep(i, 0, m - r) rep(j, 0, m) cout << a[i][j].x << " \n"[j == m - 1];
  }
}
