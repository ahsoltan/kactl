/**
 * Author: Adam Soltan
 * Description: Fast biparite matching algorithm. Graph $g$ should be a list
 * of neighbors of the left partition. Returns the match for every left vertex.
 * Time: O(E \sqrt{V})
 */
#pragma once

vi match(int n, int m, vector<vi>& g) {
  vi l(n, -1), r(m, -1), q(n), d(n);
  auto dfs = [&](auto f, int u) -> bool {
    int t = exchange(d[u], 0) + 1;
    for (int v : g[u])
      if (r[v] == -1 || (d[r[v]] == t && f(f, r[v])))
        return l[u] = v, r[v] = u, 1;
    return 0;
  };
  for (int t = 0, f = 0;; t = f = 0, d.assign(n, 0)) {
    rep(i, 0, n) if (l[i] == -1) q[t++] = i, d[i] = 1;
    rep(i, 0, t) for (int v : g[q[i]]) {
      if (r[v] == -1) f = 1;
      else if (!d[r[v]]) d[r[v]] = d[q[i]] + 1, q[t++] = r[v];
    }
    if (!f) return l;
    rep(i, 0, n) if (l[i] == -1) dfs(dfs, i);
  }
}
