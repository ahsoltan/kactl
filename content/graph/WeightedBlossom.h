/**
 * Author: MIT, Adam Soltan
 * Description: General max weight matching. Edge weights must be positive.
 * Time: O(n^3), faster in practice
 */
#pragma once

template<int SZ> struct WeightedBlossom { 
  struct Edge { int u, v, w; }; Edge g[SZ*2][SZ*2];
  int N,NX,lab[SZ*2],match[SZ*2],slack[SZ*2],st[SZ*2];
  int par[SZ*2],floFrom[SZ*2][SZ],S[SZ*2],aux[SZ*2]; 
  vi flo[SZ*2]; queue<int> q;
  void init(int _N) { N = _N;
    rep(u,1,N+1) rep(v,1,N+1) g[u][v] = {u,v,0}; }
  void ae(int u,int v,int w) { u++,v++,g[u][v].w=g[v][u].w=w; }
  int eDelta(Edge e) {
    return lab[e.u]+lab[e.v]-g[e.u][e.v].w*2; } 
  void updSlack(int u, int x) {
    if (!slack[x] || eDelta(g[u][x]) < eDelta(g[slack[x]][x])) 
      slack[x] = u; }
  void setSlack(int x) {
    slack[x] = 0; rep(u,1,N+1) if (g[u][x].w > 0
     && st[u] != x && S[st[u]] == 0) updSlack(u,x); }
  void qPush(int x) {
    if (x <= N) q.push(x);
    else for (int t : flo[x]) qPush(t); }
  void setSt(int x, int b) {
    st[x] = b; if (x > N) for (int t : flo[x]) setSt(t,b); }
  int getPr(int b, int xr) {
    int pr = find(all(flo[b]),xr)-begin(flo[b]);
    if (pr&1) { reverse(1+all(flo[b])); return sz(flo[b])-pr; }
    return pr; }
  void setMatch(int u, int v) {
    Edge e = g[u][v]; match[u] = e.v; if (u <= N) return;
    int xr = floFrom[u][e.u], pr = getPr(u,xr);
    rep(i, 0, pr) setMatch(flo[u][i],flo[u][i^1]);
    setMatch(xr,v); rotate(begin(flo[u]),pr+all(flo[u])); }
  void augment(int u, int v) {
    while (1) {
      int xnv = st[match[u]]; setMatch(u,v); 
      if (!xnv) return; 
      setMatch(xnv,st[par[xnv]]); 
      u = st[par[xnv]], v = xnv; 
    }
  }
  int lca(int u, int v) {
    static int t = 0;
    for (++t;u||v;swap(u,v)) {
      if (!u) continue;
      if (aux[u] == t) return u;
      aux[u] = t; u = st[match[u]];
      if (u) u = st[par[u]];
    }
    return 0;
  }
  void addBlossom(int u, int anc, int v) { 
    int b = N+1; while (b <= NX && st[b]) ++b;
    if (b > NX) ++NX;
    lab[b] = S[b] = 0; match[b] = match[anc]; flo[b] = {anc};
    auto blossom = [&](int x) {
      for (int y; x != anc; x = st[par[y]])  {
        flo[b].push_back(x), flo[b].push_back(y=st[match[x]]);
        qPush(y);
      }
    };
    blossom(u); reverse(1+all(flo[b])); blossom(v); setSt(b,b);
    rep(x,1,NX+1) g[b][x].w = g[x][b].w = 0;
    rep(x,1,N+1) floFrom[b][x] = 0;
    for(int xs : flo[b]) {
      rep(x,1,NX+1) if (g[b][x].w == 0 || eDelta(g[xs][x]) < 
        eDelta(g[b][x])) g[b][x]=g[xs][x], g[x][b]=g[x][xs]; 
      rep(x,1,N+1) if (floFrom[xs][x]) floFrom[b][x] = xs; 
    }
    setSlack(b);
  }
  void expandBlossom(int b) {
    for (int t : flo[b]) setSt(t,t);
    int xr = floFrom[b][g[b][par[b]].u], pr = getPr(b,xr);
    for(int i = 0; i < pr; i += 2) {
      int xs = flo[b][i], xns = flo[b][i+1];
      par[xs] = g[xns][xs].u; S[xs] = 1;
      S[xns] = slack[xs] = slack[xns] = 0; qPush(xns);
    }
    S[xr] = 1, par[xr] = par[b];
    rep(i,pr+1,sz(flo[b])) {
      int xs = flo[b][i]; S[xs] = -1, setSlack(xs); }
    st[b] = 0;
  }
  bool onFoundEdge(Edge e) {
    int u = st[e.u], v = st[e.v];
    if (S[v] == -1) {
      par[v] = e.u, S[v] = 1; slack[v] = 0;
      int nu = st[match[v]]; S[nu] = slack[nu] = 0; qPush(nu);
    } else if (S[v] == 0) {
      int anc = lca(u,v);
      if (!anc) return augment(u,v),augment(v,u),1;
      addBlossom(u,anc,v);
    }
    return 0;
  }
  bool matching() {
    q = queue<int>(); 
    rep(x,1,NX+1) {
      S[x] = -1, slack[x] = 0;
      if (st[x] == x && !match[x]) par[x] = S[x] = 0, qPush(x); 
    } 
    if (!sz(q)) return 0;
    while (1) {
      while (sz(q)) {
        int u=q.front(); q.pop(); if (S[st[u]] == 1) continue;
        rep(v,1,N+1) if (g[u][v].w > 0 && st[u] != st[v]) { 
          if (eDelta(g[u][v]) == 0) {
            if (onFoundEdge(g[u][v])) return 1;
          } else updSlack(u,st[v]);
        }
      }
      int d = INT_MAX; 
      rep(b,N+1,NX+1) if (st[b] == b && S[b] == 1) 
        d = min(d,lab[b]/2);
      rep(x,1,NX+1) if (st[x] == x && slack[x]) {
        if (S[x] == -1) d=min(d,eDelta(g[slack[x]][x]));
        else if (S[x] == 0) d=min(d,eDelta(g[slack[x]][x])/2);
      }
      rep(u,1,N+1) {
        if (S[st[u]] == 0) {
          if (lab[u] <= d) return 0;
          lab[u] -= d;
        } else if (S[st[u]] == 1) lab[u] += d;
      }
      rep(b,N+1,NX+1) if (st[b] == b && S[b] != -1) 
        lab[b] += (S[b] == 0 ? 1 : -1)*d*2;
      q = queue<int>();
      rep(x,1,NX+1) if (st[x]==x && slack[x]
        && st[slack[x]] != x && eDelta(g[slack[x]][x]) == 0)
          if (onFoundEdge(g[slack[x]][x])) return 1;
      rep(b,N+1,NX+1) if (st[b]==b && S[b]==1 && lab[b]==0) 
        expandBlossom(b);
    }
    return 0;
  }
  pair<ll, vi> calc() {
    NX = N; st[0] = 0; rep(i,1,2*N+1) aux[i] = 0;
    rep(i,1,N+1) match[i] = 0, st[i] = i, flo[i].clear();
    int wMax = 0;
    rep(u,1,N+1) rep(v,1,N+1)
      floFrom[u][v] = (u==v ? u : 0), wMax=max(wMax,g[u][v].w);
    rep(u,1,N+1) lab[u] = wMax;
    ll w = 0; vi mt(N, -1); while (matching());
    rep(i, 1, N + 1) if (match[i])
      w += g[i][match[i]].w, mt[i-1] = match[i]-1;
    return {w / 2, mt};
  }
};
