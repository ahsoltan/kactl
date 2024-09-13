/**
 * Author: KACTL
 * Description: Treap with lazy propagation and parent information.
 * It acts as a sequential container with log-time splits/joins, and
 * is easy to augment with additional data.
 * Time: $O(\log n)$
 */
#pragma once

mt19937 rng(2137);
struct Node {
  Node *l = 0, *r = 0, *p = 0;
  int val, pr, c = 1;
  Node(int x) : val(x), pr(rng()) {}
  void pull();
  void push();
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::pull() { c = cnt(l) + cnt(r) + 1; }
void Node::push() {}

pair<Node*, Node*> split(Node* n, int k) {
  if (!n) return {};
  n->push();
  if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
    auto pa = split(n->l, k);
    n->l = pa.second;
    n->p = 0;
    if (n->l) n->l->p = n;
    n->pull();
    return {pa.first, n};
  } else {
    auto pa = split(n->r, k - cnt(n->l) - 1); // and just "k"
    n->r = pa.first;
    n->p = 0;
    if (n->r) n->r->p = n;
    n->pull();
    return {n, pa.second};
  }
}
Node* merge(Node* l, Node* r) {
  if (!l || !r) return l ?: r;
  if (l->pr > r->pr) {
    l->push();
    l->r = merge(l->r, r);
    l->r->p = l;
    l->pull();
    return l;
  } else {
    r->push();
    r->l = merge(l, r->l);
    r->l->p = r;
    r->pull();
    return r;
  }
}
