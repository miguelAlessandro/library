#include <bits/stdc++.h>
using namespace std;

struct line{
	int a, b;

	bool operator<(const line& p) const{
		return a < p.a or a == p.a and b > p.b;
	}
};

vector<line> CHT;

int cross(const line O, const line A, const line B){
	return (A.a - O.a) * (B.b - O.b) - (B.a - O.a) * (A.b - O.b);
}

void add(const line X){
	int n = CHT.size();
	while(n >= 2 and cross(CHT[n-2], CHT[n-1], X) >= 0) n--;
	
	CHT.resize(n);
	CHT.push_back(X);
}

int p(int mid, int x){
	return CHT[mid].a * x + CHT[mid].b;
}

int query(int x){

	int lo = 0, hi = (int)CHT.size()-1;
	while(lo < hi){
		int mid = lo + (hi-lo)/2;
		if(p(mid, x) > p(mid+1, x)) lo = mid+1;
		else hi = mid;
	}

	return p(lo, x);
}

//x is monotic ~ q: querys O(n/q + 1)
struct Query{
	int head;	
	Query():head(0){};
	int operator()(int x){
		if(head >= CHT.size()) head = (int)CHT.size() - 1;
		while(head + 1 < CHT.size() and p(head, x) > p(head+1, x)) head += 1;
		return p(head, x);
	}
};

int main(){

	add({2, 0});
	cout << query(-2) << endl;
	cout << query(2) << endl;

	add({0, -1});
	cout << query(-2) << endl;
	cout << query(2) << endl;

	add({1, 1});	
	cout << query(-2) << endl;
	cout << query(2) << endl;

	add({-1, 0});	
	cout << query(-2) << endl;
	cout << query(2) << endl;

	return 0;
}
