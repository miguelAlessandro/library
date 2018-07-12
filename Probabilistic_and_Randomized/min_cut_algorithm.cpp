#include <bits/stdc++.h>
using namespace std;

const int SIZE_E = 1000 + 5;
const int SIZE_V = 1000 + 5;
int id[SIZE_V], rnk[SIZE_V];
struct edge {
  int u, v; 
}
vector<edge> List;


int get (int x) {
  return x != id[x] ? get(id[x]) : x;
}

int components;
void Union(int u, int v) {
  u = get(u);
  v = get(v);
  
  if (u == v) return;
  
  components --;
  
  if (rnk[u] < rnk[v]) swap(u, v);
  id[v] = u;
  rnk[u] += rnk[u]==rnk[v];
}

bool same(int u, int v) {
  return get(u) == get(v);
}

void init (int V) {
  for (int i = 1; i <= V; ++i) {
    id[i] = i;
    rnk[i] = 0;
  }
  components = V;
}

int karger_min_cut(vector<edge> List, int V, int E) {
 
  init(V);
  shuffle (List.begin(), List.end());
  for (edge e : List) {
    if (components <= 2) break;
    Union(e.u, e.v);
  }
  
  int cut = 0;
  for (edge e : List)
    cut += not same(e.u, e.v);
  
  return cut;
}
