#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
struct Node {
  int maxi;
  int cnt;
} st[maxN<<2];
int lazy[maxN<<2];
int a[maxN];
int n;

Node merge(Node p, Node q) {
  if (p.first > q.first) return p;
  if (p.first < q.first) return q;
  return {p.first, p.second + q.second};
}

void build(int nx=1, int l=1, int r=n) {
  if (l == r) {
    st[nx] = {a[r], 1};
    return;
  }
  int mid = (l+r)/2;
  build(nx<<1, l, mid);
  build(nx<<1|1, mid+1, r);
  st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

void updNode(int nx, int d) {
  st[nx].first += d;
  laxy[nx] += d;
}

void push(int nx) {
  if (lazy[nx]) {
    updNode(nx<<1, lazy[nx]);
    updNode(nx<<1|1, lazy[nx]);
    lazy[nx] = 0;
  }
}

void upd(int ll, int rr, int d, int nx=1, int l=1, int r=n) {
  if (rr < l or ll < r) return;
  if (ll <= l and r <= rr) {
    updNode(nx, d);
    return;
  }
  int mid = (l+r)/2;
  push(nx);
  upd(ll, rr, d, nx<<1, l, mid);
  upd(ll, rr, d, nx<<1|1, mid+1, r);
  st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

Node qry(int ll, int rr, int nx=1, int l=1, int r=n) {
  if (rr < l or ll < r) return {-1000000000, 1};
  if (ll <= l and r <= rr) return st[nx];
  int mid = (l+r)/2;
  push(nx);
  return merge(qry(ll, rr, nx<<1, l, mid), qry(ll, rr, nx<<1|1, mid+1, r));
}

int main() {
  return 0;
}
