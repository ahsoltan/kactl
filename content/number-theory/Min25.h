/**
 * Author: Nyaan, Adam Soltan
 * Description: Fast multiplicative function prefix sums.
 * Requires \texttt{isPrime} calculated up to $\sqrt{n}$.
 * Time: O(\tfrac{n^{3/4}}{\log n})
 */
#pragma once

#include "FastEratosthenes.h"

template<class T> struct Min25 {
  ll n, sq, s; vi p;
  Min25(ll _n) : n(_n) {
    sq = sqrtl(n) + 5;
    while (sq * sq > n) sq--;
    ll hls = quo(n, sq);
    while (hls != 1 && quo(n, hls - 1) == sq) hls--;
    s = hls + sq;
    rep(i, 2, sq + 1) if (isPrime[i]) p.push_back(i);
  }
  vector<T> sieve(auto f) {
    ll hls = s - sq;
    vector<T> h(s);
    rep(i, 1, hls) h[i] = f(quo(n, i)) - 1;
    rep(i, 1, sq + 1) h[s - i] = f(i) - 1;
    for (int x : p) {
      T xt = f(x) - f(x - 1), pi = h[s - x + 1];
      ll x2 = 1ll * x * x, imax = min(hls, quo(n, x2) + 1);
      for (ll i = 1, ix = x; i < imax; i++, ix += x)
        h[i] -= ((ix < hls ? h[ix] : h[s-quo(n, ix)])-pi) * xt;
      for (int i = sq; i >= x2; i--)
        h[s - i] -= (h[s - quo(i, x)] - pi) * xt;
    }
    return h;
  }
  vector<T> unsieve(const vector<T>& fp, auto f) {
    vector<ll> ns = {0};
    rep(i, 1, s - sq) ns.push_back(quo(n, i));
    rep(i, 0, sq) ns.push_back(sq - i);
    auto F = fp, G = fp;
    for (ll P : p | views::reverse) {
      for (ll pk = P, k = 1; quo(n, P) >= pk; k++, pk *= P) {
        T x = fp[idx(P)], y = f(P, k, pk), z = f(P, k+1, pk*P);
        rep(i, 1, s) {
          ll m = ns[i];
          if (P * pk > m) break;
          G[i] += y * (F[idx(quo(m, pk))] - x) + z;
        }
      }
      copy_n(G.begin(), min((int)s, idx(P*P) + 1), F.begin());
    }
    rep(i, 1, sz(ns)) F[i] += 1;
    return F;
  }
  ll quo(ll a, ll b) { return (double)a / b; }
  int idx(ll a) { return a <= sq ? s - a : quo(n, a); }
};
