/**
 * Author: Adam Soltan
 * Description: Finds the left and right tangent vertices of a convex polygon relative
 * to point $a$. The polygon must have at least $3$ vertices, be CCW-ordered, and no collinear
 * points. Returns the vertex indices.
 * Time: O(\log n)
 * Status: Tested on https://codeforces.com/contest/1906/problem/D
 */
#pragma once

#include "Point.h"

template<class P>
pii hullTangents(const vector<P>& p, P a) {
  int n = sz(p), t[2];
  rep(it, 0, 2) {
    auto dir = [&](int i) {
      P u = p[i] - a, v = p[(i + 1) % n] - a;
      auto c = u.cross(v);
      if (c != 0) return c < 0;
      if (u.dot(v) <= 0) return true;
      return u.dist2() > v.dist2();
    };
    auto idir = [&](int i) { return dir(i) ^ it; };
    if (idir(0) && !idir(n - 1)) { t[it] = 0; continue; }
    int s[2] = {0, n - 1};
    while (s[1] - s[0] > 2) {
      int mid = (s[0] + s[1]) / 2, x = idir(mid);
      if (idir(s[x ^ 1]) == (x ^ 1)) {
        s[x] = mid;
      } else {
        bool b = a.cross(p[mid], p[s[1]]) < 0;
        s[b ^ x ^ it ^ 1] = mid;
      }
    }
    t[it] = s[0] + 1 + (idir(s[0] + 1) == 0);
  }
  return {t[0], t[1]};
}
