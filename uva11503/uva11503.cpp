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
	TestCase() {
		process();
	}
private:
	int friends_count;
	map<string,int> mapping;


	void process() {
		int N;
		cin>>N;
		UnionFind uf(2*N);
		friends_count = 0;
		for (int i=0;i<N;++i) {
			int idx1,idx2;
			string name;
			cin>>name;
			idx1 = name_to_idx(name);
			cin>>name;
			idx2 = name_to_idx(name);
			uf.unionSet(idx1,idx2);
			cout<<uf.sizeOfSet(idx1)<<endl;
		}
	}

	int name_to_idx(const string& name) {
		int idx = 0;
		if (mapping.find(name)==mapping.end()) {
			idx = friends_count;
			mapping[name]=friends_count++;
		} else {
			idx = mapping[name];
		}
		return idx;
	}
};


int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	while (T--) {
		TestCase();
	}
	return 0;
}