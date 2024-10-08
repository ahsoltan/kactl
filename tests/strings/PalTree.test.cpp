#define PROBLEM "https://judge.yosupo.jp/problem/eertree"
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

#include "content/strings/PalTree.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  PalTree<26> t;
  vi v(sz(s));
  rep(i, 0, sz(s)) v[i] = t.add(s[i] - 'a');
  vi p(sz(t.t));
  rep(i, 0, sz(p)) for (int j : t.t[i].next) if (j) p[j] = i;
  cout << sz(p) - 2 << '\n';
  auto f = [](int x) { return !x ? 0 : (x == 1 ? -1 : x - 1); };
  rep(i, 2, sz(p)) cout << f(p[i]) << ' ' << f(t.t[i].link) << '\n';
  rep(i, 0, sz(s)) cout << f(v[i]) << " \n"[i == sz(s) - 1];
}
