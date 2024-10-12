/**
 * Author: Lucian Bicsi
 * Date: 2015-06-25
 * License: GNU Free Documentation License 1.2
 * Source: csacademy
 * Description: Transform to a basis with fast convolutions of the form
 * $\displaystyle c[z] = \sum\nolimits_{z = x \oplus y} a[x] \cdot b[y]$,
 * where $\oplus$ is one of AND, OR, XOR. The size of $a$ must be a power of two.
 * Time: O(N \log N)
 * Status: stress-tested
 */
#pragma once

template<class T>
void FST(vector<T>& a, bool inv) {
  for (int n = sz(a), step = 1; step < n; step *= 2) {
    for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
      T &u = a[j], &v = a[j + step]; tie(u, v) =
#if defined(AND) // exclude-line
        inv ? pair(v - u, u) : pair(v, u + v); // AND
#elif defined(OR) // exclude-line
        inv ? pair(v, u - v) : pair(u + v, u); // OR
#elif defined(XOR) // exclude-line
        pair(u + v, u - v);                    // XOR
#endif // exclude-line
    }
  }
#if defined(XOR) // exclude-line
  if (inv) for (T& x : a) x /= sz(a); // XOR only
#endif // exclude-line
}
template<class T>
vector<T> conv(vector<T> a, vector<T> b) {
  FST(a, 0); FST(b, 0);
  rep(i, 0, sz(a)) a[i] *= b[i];
  FST(a, 1); return a;
}
