/**
 * Author: MIT
 * Description: Constructs a cyclic string from the alphabet $[0, k)$
 * of length $k^n$ that contains every length $n$ string as a substring.
 */
#pragma once

vi deBruijnSeq(int k, int n) {
  if (k == 1) return {0};
  vi seq, aux(n + 1); 
  auto rec = [&](auto f, int t, int p) -> void {
    if (t > n) {
      if (n % p == 0) rep(i, 1, p + 1) seq.push_back(aux[i]);
    } else {
      aux[t] = aux[t - p]; f(f, t + 1, p);
      while (++aux[t] < k) f(f, t + 1, t);
    }
  };
  return rec(rec, 1, 1), seq;
}
