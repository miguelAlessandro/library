/*
	convex hull algorithm:

	let P a set of points, compute
	CH(p): convez hull of p 

	time complexity: O(n log n)
	memory complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point{
	int x, y;
	bool operator<(const Point& p) const{
		return x < p.x or x == p.x and y < p.y;
	}
};

ll cross(const Point O, const Point A, const Point B){
	return (A.x - O.x) * 1ll * (B.y - O.y) - (A.y - O.y) * 1ll * (B.x - O.x);
}


vector<Point> convex_hull(vector<Point>& P){

	vector<Point> CH(int(P.size())<<1);
	int n = 0;

	sort(P.begin(), P.end());

	for(int i = 0; i < P.size(); ++i){
		while(n > 2 and cross(CH[n-2], CH[n-1], P[i]) >= 0) n--;
		CH[n] = P[i];
	}

	for(int i = (int)P.size()-2, t = n; i >= 0; --i){
		while(n > t+1 and cross(CH[n-2], CH[n-1], P[i]) >= 0) n--;
		CH[n] = P[i];
	}

	CH.resize(n-1);
	return CH;
}

int main(){

	return 0;
}
