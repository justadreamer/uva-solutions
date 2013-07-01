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
typedef set<int> si;

class TestCase {
public:
	TestCase(int k) {
		process(k);
	}
private:
	void process(int k) {
		vi numbers(k,0);
		for (int i=0;i<k;++i) {
			cin>>numbers[i];
		}

		si choose;
		choose_next(choose,numbers);
	}

	void choose_next(si& choose, const vi& numbers) {
		const int max = 6;
		if (choose.size()==max) {
			for (si::iterator i = choose.begin();i!=choose.end();++i) {
				if (i!=choose.begin())
					cout<<" ";
				cout<<numbers[*i];
			}
			cout<<endl;
			return;
		}
		for (int i=choose.size() ? *(choose.rbegin()) : 0; i<numbers.size(); ++i) {
			pair<si::iterator,bool> p = choose.insert(i);
			if (p.second) {
				choose_next(choose,numbers);
			} else {
				continue;
			}
			choose.erase(p.first);
		}
	}
};


int main(int argc, char* argv[])
{
	int k;
	bool is_first = true;
	while (cin>>k && k) {
		if (is_first) {
			is_first = false;
		} else {
			cout<<endl;
		}
		TestCase t(k);
	}
	return 0;
}