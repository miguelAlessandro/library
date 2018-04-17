#include <iostream>
#include <cstdio>
using namespace std;

const int maxN = 1e5 + 5;

struct node_treap{
    int key, prior;
    int l, r;
    int cnt;
} T[maxN];

int elements = 0;

int cnt(int t){
    return t ? T[t].cnt : 0;
}

int upd(int t){
    if(t) 
	T[t].cnt = cnt(T[t].l) + 1 + cnt(T[t].r);
}

// split tree with root t in the trees l, r
// keys(t) = [minimum_key, maximum_key]
// keys(l) = [minimum_key, key)
// keys(r) = [key, maximum_key]
void split(int t, int& l, int& r, int key){
    if(t == 0) l = r = 0;
    else if(T[t].key < key) 
	split(T[t].r, T[t].r, r, key), l = t;
    else
	split(T[t].l, l, T[t].l, key), r = t;
    upd(t);
}

// merge trees l and r in tree t
// necessary: maximum_key(l) \leq minimum_key(r)
void merge(int& t, int l, int r){
    if(l == 0 or r == 0) t = l ^ r;
    else if(T[l].prior < T[r].prior)
	merge(T[l].r, T[l].r, r), t = l;
    else
        merge(T[r].l, l, T[r].l), t = r;
    upd(t);
}

// insert element {key, prior}
void insert(int& t, int key, int prior){
    T[++elements] = {key, prior, 0, 0, 1};
    if(t == 0) t = elements;
    else{
	int r;
	split(t, t, r, key);
        merge(t, t, elements);
        merge(t, t, r);
    }
}

// delete all element with key = 'key'
void erase(int& t, int key){
    int mid, r;
    split(t, t, mid, key);
    split(mid, mid, r, key+1);
    merge(t, t, r);
}

int main(){


    return 0;
}

