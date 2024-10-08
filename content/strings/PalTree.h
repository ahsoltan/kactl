/**
 * Author: UW1, Adam Soltan
 * Description: Palindrome tree. To count occurrences of each palindrome,
 * after every \texttt{add} add $1$ to vertices on the suffix link path
 * from \texttt{last} to the root.
 * Time: O(26 N)
 */
#pragma once

template<int A> struct PalTree {
  struct Node { int len = 0, next[A] = {}, link = 0; };
  vector<Node> t;
  vi s = {-1};
  int last = 0;
  PalTree() : t(2) { t[0].link = 1; t[1].len = -1; }
  int find(int u) {
    while (s.back() != s[sz(s) - t[u].len - 2]) u = t[u].link;
    return u;
  }
  int add(int c) {
    s.push_back(c);
    last = find(last);
    if (!t[last].next[c]) {
      Node& n = t.emplace_back();
      n.len = t[last].len + 2;
      n.link = t[find(t[last].link)].next[c];
      t[last].next[c] = sz(t) - 1;
    }
    return last = t[last].next[c];
  }
};
