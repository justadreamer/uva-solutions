#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>

using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
private:
	int ans_true;
	int ans_false;
};

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	cin.ignore();
	cin.ignore();
	for (int i=0;i<T;i++) {
		if (i>0)
			cout<<endl;//print a blank line between datasets
		TestCase();
	}
	return 0;
}

TestCase::TestCase() {
	input();
	output();
}

void TestCase::input() {
	int N;
	cin>>N;
	cin.ignore();
	UnionFind uf(N+1);
	ans_true = 0;
	ans_false = 0;
	string s;
	while (getline(cin,s) && s.length()) {
		char c;
		int i,j;
		sscanf(s.c_str(),"%c %d %d",&c,&i,&j);
		if (c=='c') {
			uf.unionSet(i,j);
		} else if (c=='q') {
			if (uf.isSameSet(i,j)) 
				++ans_true;
			else
				++ans_false;
		}
	};
}

void TestCase::output() {
	cout<<ans_true<<","<<ans_false<<endl;
}