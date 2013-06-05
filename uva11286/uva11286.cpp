#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>
#include <set>
#include <iomanip>
#include <list>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

class TestCase {
public:
	TestCase();
	bool dotest();
};

int main(int argc, char* argv[])
{
	int T;
	while (true) {
		TestCase t;
		if (!t.dotest()) {
			break;
		}
	}
	return 0;
}

TestCase::TestCase() {

}

bool TestCase::dotest() {
	int n = 0;
	cin>>n;
	if (!n)
		return false;
	typedef map<set<int>,int> msii;
	msii mapping;
	int const MAX_COURSES = 5;
	for (int i=0;i<n;++i) {
		set<int> courses;
		for (int j=0;j<MAX_COURSES;++j) {
			int course;
			cin>>course;
			courses.insert(course);
		}
		if (mapping.find(courses)==mapping.end()) {
			mapping[courses]=1;
		} else {
			++mapping[courses];
		}
	}
	priority_queue<int> pq;
	for (msii::iterator i = mapping.begin();i!=mapping.end();++i) {
		pq.push(i->second);
	}
	int popular = pq.top();
	int popularity = 0;
	while (pq.size() && pq.top()==popular) {
		popularity+=pq.top();
		pq.pop();
	}
	cout<<popularity<<endl;
	return true;
}