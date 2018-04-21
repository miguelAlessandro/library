/*
	polygon convex hull

	let P a polygon, compute 
	convex hull of p

	time complexity: O(n)
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

ll cross(Point O, Point A, Point B){
	return (A.x - O.x) * 1ll * (B.y - O.y) - (A.y - O.y) * 1ll * (B.x - O.x);
}

vector<Point> polygon_convex_hull(vector<Point>& P){

	vector<Point> CH(P.size());
	int n = 0;

	int id = 0;
	for(int i = 1; i < P.size(); ++i)
		if(P[i] < P[id])
			id = i;

	for(int i = 0; i < P.size() + 1; ++i){
		while(n > 2 and cross(CH[n-2], CH[n-1], P[(id + i)%n]) >= 0) n--;
		CH[n] = P[(id+i)%n]; 
	}

	CH.resize(n-1);
	return CH;
}

int main(){

	return 0;
}
