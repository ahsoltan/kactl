/**
 * Author: https://codeforces.com/blog/entry/57496, Adam Soltan
 * Description: Fast computation of chromatic number.
 * Time: O(n 2^n)
 */
#pragma once

const int MOD = 1034865179; // random large prime
int chromaticNumber(vi& g) {
  int n = sz(g);
  vi dp(1 << n), f(n); dp[0] = 1;
  rep(i, 1, 1 << n) {
    int ctz = __builtin_ctz(i), j = i - (1 << ctz);
    dp[i] = dp[j] + dp[j & ~g[ctz]];
    if (dp[i] >= MOD) dp[i] -= MOD;
  }
  rep(i, 0, 1 << n) {
    ll x = (n - __builtin_parity(i)) & 1 ? MOD - 1 : 1;
    rep(j, 0, n) {
      if ((f[j] += x) >= MOD) f[j] -= MOD;
      x = x * dp[i] % MOD;
    }
  }
  rep(i, 0, n) if (f[i]) return i;
  return n;
}
