/**
 * Author: Krzysztof Potepa, Adam Soltan
 * Description: Main-Lorentz algorithm for finding all squares in a string.
 * Returns triples $(l, r, t)$ signifying that for each $i \in [l, r)$ there
 * is a square at position $i$ of size $2t$. Triples with the same $t$ don't
 * intersect or touch.
 * Time: O(n \log n)
 */
#pragma once

#include "Zfunc.h"

vector<array<int, 3>> squares(const string& s) {
  vector<array<int, 3>> ans; vi pos(sz(s) / 2 + 2, -1);
  rep(m, 1, sz(s)) {
    int p = m & ~(m - 1), o = m - p, e = min(m + p, sz(s));
    auto a = s.substr(o, p), b = s.substr(m, e - m);
    auto ra = a, rb = b; reverse(all(ra)); reverse(all(rb));
    rep(j, 0, 2) {
      vi z1 = Z(ra), z2 = Z(b + '\0' + a);
      z1.push_back(0); z2.push_back(0);
      rep(c, 0, sz(a)) {
        int l = sz(a) - c;
        int x=c-min(l-1, z1[l]), y=c-max(l-z2[sz(b)+c+1], j);
        if (x > y) continue;
        int sb = j ? e-y-l*2 : o+x, se = j ? e-x-l*2+1 : o+y+1;
        int& k = pos[l];
        if (k != -1 && ans[k][1] == sb) ans[k][1] = se;
        else k = sz(ans), ans.push_back({sb, se, l});
      }
      swap(a, rb); swap(b, ra);
    }
  }
  return ans;
}
