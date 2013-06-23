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

struct node {
	node():is_awake(false) {}
	vector<char> adj; //adjacent nodes
	bool is_awake;
};

int const NEED_TO_WAKE = 3;

class TestCase {
public:
	TestCase(int _N) {
		process(_N);
	}
private:
	void process(int N) {
		map<char,node> graph;
		int e;
		cin>>e;
		char wake_up_nodes[NEED_TO_WAKE+1];
		scanf("%s",wake_up_nodes);

		for (int i=0;i<NEED_TO_WAKE;++i) {
			node n;
			n.is_awake = true;
			graph[wake_up_nodes[i]] = n;
		}

		for (int i=0;i<e;++i) {
			char edge[3];
			scanf("%s",edge);
			graph[edge[0]].adj.push_back(edge[1]);
			graph[edge[1]].adj.push_back(edge[0]);
		}

		if (N>graph.size()) {
			never_awake();
			return;
		}

		int n_years = -1;
		bool is_all_awake = false;
		while(!is_all_awake) {
			is_all_awake = true;
			vector<char> to_awake;
			for (map<char,node>::iterator i=graph.begin();i!=graph.end();++i) {
				if (!i->second.is_awake) {
					vector<char>& adj = i->second.adj;
					if (adj.size()<NEED_TO_WAKE) {
						never_awake();
						return;
					}

					is_all_awake = false;
					int n_awake_adj = 0;
					for (vector<char>::iterator j=adj.begin();j!=adj.end();++j) {
						if (graph[*j].is_awake)
							++n_awake_adj;
					}
					if (n_awake_adj>=NEED_TO_WAKE) {
						to_awake.push_back(i->first);
					}
				}
			}

			if (to_awake.size()==0 && !is_all_awake) {
				never_awake();
				return;
			}

			for (vector<char>::iterator i=to_awake.begin();i!=to_awake.end();++i) {
				graph[*i].is_awake = true;
			}
			++n_years;
		}

		cout<<"WAKE UP IN, "<<n_years<<", YEARS"<<endl;
	}

	void never_awake() {
		cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
	}
private:
	int N;
};

int main(int argc, char* argv[])
{
	int N;
	while (cin>>N) {
		TestCase t(N);
	}
	return 0;
}