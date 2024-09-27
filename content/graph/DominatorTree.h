/**
 * Author: MIT, Adam Soltan
 * Description: Finds the parent of each vertex in the dominator tree of $g$.
 * Vertex $a$ dominates vertex $b$ iff every path from $\mathit{src}$ to $b$ passes through $a$.
 * Time: O(m \log n)
 */
#pragma once

vi dominatorTree(vector<vi>& g, int src) {
  int n = sz(g), tt = 0;
  vi ans(n, -1), t(n, -1), rt(n), s(n), p(n), d(n), b(n);
  vector<vi> c(n), r(n), sc(n);
  auto get = [&](auto f, int u) -> int {
    if (p[u] != u) {
      int v = f(f, p[u]); p[u] = p[p[u]];
      if (s[v] < s[b[u]]) b[u] = v;
    }
    return b[u];
  };
  auto dfs = [&](auto f, int u) -> void {
    t[u] = tt, rt[tt] = u;
    s[tt] = p[tt] = b[tt] = tt; tt++;
    for (int v : g[u]) {
      if (t[v] == -1) f(f, v), c[t[u]].push_back(t[v]);
      r[t[v]].push_back(t[u]);
    }
  };
  dfs(dfs, src);
  for (int i = tt - 1; i >= 0; i--) {
    for (int j : r[i]) s[i] = min(s[i], s[get(get, j)]);
    if (i) sc[s[i]].push_back(i);
    for (int j : sc[i]) {
      int k = get(get, j);
      d[j] = s[j] == s[k] ? s[j] : k;
    }
    for (int j : c[i]) p[j] = i;
  }
  rep(i, 1, tt) {
    if (d[i] != s[i]) d[i] = d[d[i]];
    ans[rt[i]] = rt[d[i]];
  }
  return ans;
}
