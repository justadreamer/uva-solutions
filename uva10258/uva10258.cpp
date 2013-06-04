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

using namespace std;

struct submission {
	int contestant;
	int problem;
	int penalty;
	char verdict;

	void output() {
		cout<<contestant<<" "<<problem<<" "<<penalty<<" "<<verdict<<endl;
	}
};

struct rank {
	rank():penalty(0) {};
	int contestant;
	int problems() const {
		return solved_problems.size();
	}
	int penalty;
	set<int> solved_problems;
	map<int,int> unsolved_problems_penalties;

	void output() const {
		cout<<contestant<<" "<<problems()<<" "<<penalty<<endl;
	}
};


struct comparison {
	bool operator()(const rank& rank1, const rank& rank2) {
		if (rank1.problems()!=rank2.problems()) {
			return rank1.problems()>rank2.problems();
		} else if (rank1.penalty!=rank2.penalty) {
			return rank1.penalty<rank2.penalty;
		} 
		return rank1.contestant<rank2.contestant;
	}
};

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
private:
	vector<submission> submissions;	
	set<rank,comparison> sorted_ranks;
};


int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	cin.ignore();
	cin.ignore();
	for (int i=0;i<T;i++) {
		TestCase();
		if (i<T-1) {
			cout<<endl;
		}
	}
	return 0;
}

TestCase::TestCase() {
	input();
	calc();
	output();
}

void TestCase::input() {
	submission s;
	char c;
	string buf;
	while (getline(cin,buf) && buf.length()>0) {
		stringstream stream(buf,ios_base::in);
		stream>>s.contestant>>s.problem>>s.penalty>>s.verdict;
		submissions.push_back(s);
	}
}

void TestCase::calc() {
	map<int,rank> ranks;
	for (vector<submission>::iterator i = submissions.begin();i!=submissions.end();++i) {
		rank& r = ranks[i->contestant];
		r.contestant = i->contestant;
		if(r.solved_problems.find(i->problem)==r.solved_problems.end()) {
			if (r.unsolved_problems_penalties.find(i->problem)==r.unsolved_problems_penalties.end()) {
				r.unsolved_problems_penalties[i->problem]=0;
			}

			if (i->verdict=='C') {
				r.solved_problems.insert(i->problem);
				r.penalty+=i->penalty+r.unsolved_problems_penalties[i->problem];
			} else if (i->verdict=='I') {
				r.unsolved_problems_penalties[i->problem]+=20;
			}
		}
	}

	for (map<int,rank>::iterator i = ranks.begin();i!=ranks.end();++i) {
		sorted_ranks.insert(i->second);
	}
}

void TestCase::output() {
	for (set<rank>::iterator i = sorted_ranks.begin();i!=sorted_ranks.end();++i) {
		i->output();
	}
}