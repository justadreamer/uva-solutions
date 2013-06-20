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

typedef vector<char> vc;
struct vertex {
	bool is_visited;
	vc adj_list;
	vertex() : is_visited(false) {}
};

typedef map <char, vertex> graph;

class TestCase {
public:
	TestCase() {
		input();
		calc();
		output();
	}
private:
	void input() {
		char buf[512];
		buf[0]='\0';
		while (scanf("%s",buf) && buf[0]!='*') {
			char v1 = buf[1];
			char v2 = buf[3];
			g[v1].adj_list.push_back(v2);
			g[v2].adj_list.push_back(v1);
		}
		scanf("%s",buf);
		int i=0;
		while (buf[i]!='\0') {
			char v = buf[i];
			if (isalpha(v)) {
				g[v];
			}
			++i;
		}
	}

	void calc() {
		acorns = 0;
		trees = 0;
		for (graph::iterator i=g.begin();i!=g.end();++i) {
			char v = i->first;
			vertex& vdata = i->second;
			if (vdata.is_visited)
				continue;

			if (vdata.adj_list.size()==0) {
				vdata.is_visited = true;
				++acorns;
			} else {
				recurse_tree(v);
				++trees;
			}
		}
	}

	void recurse_tree(char v) {
		vertex& vdata = g[v];
		if (vdata.is_visited)
			return;
		vdata.is_visited = true;
		for (vc::iterator i=vdata.adj_list.begin();i!=vdata.adj_list.end();++i) {
			recurse_tree(*i);
		}
	}

	void output() {
		cout<<"There are "<<trees<<" tree(s) and "<<acorns<<" acorn(s)."<<endl;
	}
private:
	graph g;
	int acorns;
	int trees;
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