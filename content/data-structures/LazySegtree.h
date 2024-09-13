/**
 * Author: Adam Soltan
 * Description: Basic segment tree template with lazy propagation.
 * Can be easily extended with advanced functionality.
 * Time: O(\log n)
 */
#pragma once

struct ST {
  struct Node {};
  int n;
  vector<Node> t;
  ST(int _n) : n(_n) { t.resize(2 * n); }
  Node join(const Node& a, const Node& b) {}
  void push(int u, int len) {} // push to u + 1, u + (len & -2)
  void rec(int u,int lo,int hi,int l,int r,bool mod,auto f) {
    if (l <= lo && hi <= r) return f(u, lo, hi);
    push(u, hi - lo);
    int mid = (lo + hi) / 2;
    if (mid > l) rec(u + 1, lo, mid, l, r, mod, f);
    if (mid < r) rec(u + (mid-lo) * 2, mid, hi, l, r, mod, f);
    if (mod) t[u] = join(t[u + 1], t[u + (mid - lo) * 2]);
  }
  Node get(int l, int r) {
    bool in = 0;
    Node res;
    rec(0, 0, n, l, r, 0, [&](int u, int, int) {
      res = in ? join(res, t[u]) : t[u], in = 1;
    });
    return res;
  }
  void modify(int l, int r) {
    rec(0, 0, n, l, r, 1, [&](int u, int lo, int hi) {});
  }
};
