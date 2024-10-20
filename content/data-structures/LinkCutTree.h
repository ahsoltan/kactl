/**
 * Author: MIT, maspy, KACTL, Adam Soltan
 * Description: Link-cut tree with path and subtree queries.
 * Path operations can be arbitrary, but subtree operations need to be reversible.
 * Current implementation supports subtree addition and sum.
 * Time: O(\log n)
 */
#pragma once

struct Node {
  Node *p, *c[2];
  Node() { p = c[0] = c[1] = 0; }
  // Vertex data
  bool rev = 0;
  ll v, s, vs = 0;
  int sz, vsz = 0;
  ll d = 0, vd = 0, cc = 0;
  void add(ll x) {
    d += x, vd += x;
    v += x, s += sz * x, vs += vsz * x;
  }
  // BST operations (flip is required)
  void push() {
    if (rev) {
      rep(i, 0, 2) if (c[i]) c[i]->flip();
      rev = 0;
    }
    if (d) {
      rep(i, 0, 2) if (c[i]) c[i]->add(d);
      d = 0;
    }
  }
  void pull() {
    s = v + vs;
    sz = 1 + vsz;
    if (c[0]) s += c[0]->s, sz += c[0]->sz;
    if (c[1]) s += c[1]->s, sz += c[1]->sz;
  }
  void flip() {
    swap(c[0], c[1]), rev ^= 1;
  }
  // Virtual operations (vd = virtual delta, cc = cancel)
  void vadd(Node* x) { // Add x, x.cc = vd
    vs += x->s;
    vsz += x->sz;
    x->cc = vd;
  }
  void vdel(Node* x) { // Push vd - x.cc, delete x, x.cc = 0
    x->add(vd - x->cc);
    vs -= x->s;
    vsz -= x->sz;
    x->cc = 0;
  }
  void vswap(Node* x, Node* y) { // Swap x.cc, y.cc
    swap(x->cc, y->cc);
  }
  // Splay operations
  int up() {
    if (!p) return -2;
    rep(i, 0, 2) if (p->c[i] == this) return i;
    return -1;
  }
  bool isRoot() { return up() < 0; }
  friend void setLink(Node* x, Node* y, int d) {
    if (y) y->p = x;
    if (d >= 0) x->c[d] = y;
  }
  void rot() {
    int x = up(); Node* pp = p;
    setLink(pp->p, this, pp->up());
    setLink(pp, c[x ^ 1], x); setLink(this, pp, x ^ 1);
    if (pp->p) pp->p->vswap(pp, this);
    pp->pull();
  }
  void fix() { if (!isRoot()) p->fix(); push(); }
  void splay() {
    for (fix(); !isRoot();) {
      if (p->isRoot()) rot();
      else if (up() == p->up()) p->rot(), rot();
      else rot(), rot();
    }
    pull();
  }
};
struct LinkCut {
  vector<Node> t;
  LinkCut(int n) : t(n) {}
  void link(int u, int v) { // link u -> v
    makeRoot(&t[v]); access(&t[u]);
    setLink(&t[v], &t[u], 0); t[v].pull();
  }
  void cut(int u, int v) { // cut u -> v
    makeRoot(&t[u]); access(&t[v]);
    t[v].c[0] = t[u].p = 0; t[v].pull();
  }
  bool connected(int u, int v) {
    return lca(&t[u], &t[v]);
  }
  Node* lca(Node* u, Node* v) {
    if (u == v) return u;
    access(u); access(v); if (!u->p) return 0;
    u->splay(); return u->p ?: u;
  }
  void access(Node* u) {
    for (Node* x = u, *y = 0; x; x = x->p) {
      x->splay();
      if (y) x->vdel(y);
      if (x->c[1]) x->vadd(x->c[1]);
      x->c[1] = y; x->pull(); y = x;
    }
    u->splay();
  }
  void makeRoot(Node* u) { access(u), u->flip(), u->push(); }
};
