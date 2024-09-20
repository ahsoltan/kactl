/**
 * Author: maspy / Adam Soltan
 * Description: Black-box algorithm for the determinant of a matrix.
 * $f$ should be a function s.t.\ $f(v) = Mv$.
 * Can add multiple iterations if order of recurrence is less than $n$.
 * Time: O(n^2 + 2n \textrm{ calls to } f)
 */
#pragma once

#include "BerlekampMassey.h"

mt19937_64 rng(2137);
mint det(int n, auto f) {
  auto rnd = [&]() {
    vector<mint> v(n);
    rep(i, 0, n) v[i] = rng() % mint::MOD;
    return v;
  };
  auto a = rnd(), b = rnd(), c = rnd();
  vector<mint> s(2 * n);
  rep(i, 0, 2 * n) {
    rep(j, 0, n) s[i] += a[j] * b[j];
    rep(j, 0, n) b[j] *= c[j];
    b = f(move(b));
  }
  auto v = berlekampMassey(s);
  if (sz(v) != n) return 0;
  mint p = 1;
  rep(i, 0, n) p *= c[i];
  return v[n - 1] / p * (n % 2 ? 1 : -1);
}
