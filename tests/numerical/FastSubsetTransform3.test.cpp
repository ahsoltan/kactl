#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
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

#define OR
#include "content/numerical/FastSubsetTransform.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int f = (1 << n) - 1;
  vector<mint> a(1 << n), b(1 << n);
  rep(i, 0, 1 << n) cin >> a[f - i].x;
  rep(i, 0, 1 << n) cin >> b[f - i].x;
  auto c = conv(move(a), move(b));
  rep(i, 0, 1 << n) cout << c[f - i].x << " \n"[i == (1 << n) - 1];
}
