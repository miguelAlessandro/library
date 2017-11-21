/*
	fractional cascading: 
	
	upper bound in k sorted list L_i:
	
	n = \sum_{i=1}^{k} | L_i |
	
	build: O(n)
	complexity: O(log(n) + k)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100002;
vector<int> A[N], M[N], L[N], R[N];
int k, n;

void merge(int i){
	int l = 0, r = 1, m = 0;
	int ls = A[i].size();
	int rs = M[i+1].size();
	M[i].resize(ls + rs/2);
	L[i].resize(ls + rs/2);	
	R[i].resize(ls + rs/2);

	while(l < ls and r < rs){
		if(A[i][l] < M[i+1][r]){
			M[i][m] = A[i][l];
			L[i][m] = l;
			R[i][m] = r-1;
			l += 1;
		}
		else if(A[i][l] > M[i+1][r]){
			M[i][m] = M[i+1][r];
			L[i][m] = max(0, l - 1);
			R[i][m] = r;
			r += 2;
		}
		else{
			M[i][m] = A[i][l];
			L[i][m] = l;
			R[i][m] = r;
			l += 1, r += 2;
		}

		m += 1;
	}

	while(r < rs){
		M[i][m] = M[i+1][r];
		L[i][m] = ls-1;
		R[i][m] = r;
		r += 2;
     		m += 1;
	}

	while(l < ls){
		M[i][m] = A[i][l];
		L[i][m] = l;
		R[i][m] = rs-1;
		l += 1;
		m += 1;
	}
}

vector<int> upper_bound(int x){

	vector<int> ans;

	int lo = 0, hi = (int)M[1].size() - 1;
	while(lo < hi){
		int mid = lo + (hi - lo + 1)/2;
		if(M[1][mid] <= x) lo = mid;
		else hi = mid-1;
	}

	ans.push_back(L[1][lo]);
	
	for(int i = 2; i <= k; ++i){
		lo = R[i-1][lo];	

		ans.push_back(L[i][lo]);
	
		if(lo+1 < M[i].size() and M[i][lo+1] <= x){
			lo += 1;
			ans.back() = L[i][lo];
		}
		if(lo > 0 and M[i][lo] > x){
			lo -= 1;
			ans.back() = L[i][lo];
		}
	}

	return ans;
}

int main(){

	cin >> k;
	for(int i = 1; i <= k; ++i){
		cin >> n;
		for(int j = 1; j <= n; ++j){
			int x; cin >> x;
			A[i].push_back(x);
		}
	}
	
	for(int i = k; i >= 1; --i){	
		if(i == k){ 
			int len = A[i].size();
			M[i].resize(len);
			L[i].resize(len);
			R[i].resize(len);
		
			for(int j = 0; j < len; ++j){
				M[i][j] = A[i][j];
				L[i][j] = j;
				R[i][j] = 0;
			}
		}
		else merge(i);
	}	

	int x;
	while(cin >> x){
		vector<int> ans = upper_bound(x);
		for(int i = 0; i < ans.size(); ++i)
			cout << ans[i] << " "; cout << endl;
	}

	return 0;
}
