#include <bits/stdc++.h>
using namespace std;

template <class T>
void order_statistics (std::vector<T> a, unsigned k)
{
	int l = 0, r = (int)a.size()-1;
    while (1) {
        if (r <= l+1) {
            if (r == l+1 and a[r] < a[l]) swap (a[l], a[r]);
        	return;
		}
        int mid = (l + r) >> 1;
        swap (a[mid], a[l+1]);
        if (a[l] > a[r]) swap (a[l], a[r]);
        if (a[l+1] > a[r]) swap (a[l+1], a[r]);
        if (a[l] > a[l+1]) swap (a[l], a[l+1]);
        int i = l+1, j = r;
        const T cur = a[l+1];
       	while (1) {
            while (a[++i] < cur);
            while (a[--j] > cur);
            if (i > j) break;
            swap (a[i], a[j]);
        }
        swap (a[l+1], a[j]);
        if (j >= k) r = j-1;
        if (j <= k) l = i;
    }
}


int main () {

	return 0;
}

