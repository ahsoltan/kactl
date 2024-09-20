/**
 * Author: Krzysztof Potepa / Adam Soltan
 * Description: Eppstein's algorithm for the $k$-th shortest walk
 * in a directed graph with non-negative edge weights.
 * Time: O((n + m) \log n + k \log k)
 * Memory: O((n + m) \log n + k)
 */
#pragma once

struct KthWalk {
  using Edge = pair<int, ll>;
  struct Node { // persistent leftist heap node
    Node *l = 0, *r = 0;
    int s; Edge e;
    Node(Edge _e) : e(_e) {}
  };
  ll d0;
  priority_queue<pair<ll, Node*>> q;
  vector<Node*> h;
  KthWalk(vector<vector<Edge>>& g, int s, int t) {
    int n = sz(g); vector<vector<Edge>> r(n);
    rep(i, 0, n) for (auto [j,w] : g[i]) r[j].push_back({i,w});
    vector<ll> d(n, LLONG_MAX);
    vi ord, p(n, -1);
    priority_queue<pair<ll, int>> pq;
    pq.push({d[t] = 0, t});
    while (sz(pq)) {
      auto [dd, u] = pq.top(); pq.pop();
      if (d[u] != -dd) continue;
      ord.push_back(u);
      for (auto [v, w] : r[u]) if (d[u] + w < d[v])
        pq.push({-(d[v] = d[u] + w), v}), p[v] = u;
    }
    if ((d0 = d[s]) == LLONG_MAX) return;
    h.resize(n);
    for (int u : ord) {
      int pp = p[u]; if (pp != -1) h[u] = h[pp];
      for (auto [v, w] : g[u]) if (d[v] != LLONG_MAX) {
        ll x = w + d[v] - d[u];
        if (x || v != pp) h[u] = merge(h[u], new Node({v, x}));
        else pp = -1;
      }
    }
    q.push({0, new Node({s, 0})});
  }
  Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ?: b;
    if(a->e.second > b->e.second) swap(a, b);
    Node* c = new Node(*a); c->r = merge(c->r, b);
    if (!c->l || c->l->s < c->r->s) swap(c->l, c->r);
    c->s = (c->r ? c->r->s : 0) + 1; return c;
  }
  ll next() { // -1 if no path
    if (!sz(q)) return -1;
    auto [d, a] = q.top(); q.pop();
    if (a->l) q.push({d - a->l->e.second + a->e.second, a->l});
    if (a->r) q.push({d - a->r->e.second + a->e.second, a->r});
    Node* t = h[a->e.first];
    if (t) q.push({d - t->e.second, t});
    return d0 - d;
  }
};
