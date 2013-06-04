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

const string LEFT("left");
const string RIGHT("right");

enum {left_bank,right_bank};

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
private:
	int n,t,m;
	vector<int> car_times;
	queue<int> left_bank_queue;
	queue<int> right_bank_queue;
};

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		if (i!=0) {
			cout<<endl;//output blank line between test cases
		}
		TestCase();
	}
	return 0;
}

TestCase::TestCase() {
	input();
	calc();
	output();
}

void TestCase::input() {
	cin>>n>>t>>m;
	for (int i=0;i<m;++i) {
		int time;
		string bank;
		cin>>time>>bank;
		car_times.push_back(time);

		if (bank==LEFT) {
			left_bank_queue.push(i);
		} else if (bank==RIGHT) {
			right_bank_queue.push(i);
		}
	}
}

void TestCase::calc() {
	
	int delivered = 0;
	queue<int> ferry;
	int global_time = 0;
	int bank = left_bank;

	while (delivered<m) {
		queue<int>& this_bank_queue = bank==left_bank ? left_bank_queue : right_bank_queue;
		while (ferry.size()) {
			car_times[ferry.front()]=global_time;
			ferry.pop();
			++delivered;
		}

		while (ferry.size()<n && this_bank_queue.size() && car_times[this_bank_queue.front()]<=global_time) {
			ferry.push(this_bank_queue.front());
			this_bank_queue.pop();
		}

		int time_to_wait = INT_MAX;

		if (left_bank_queue.size()) {
			time_to_wait = car_times[left_bank_queue.front()];
		} 
		if (right_bank_queue.size() && car_times[right_bank_queue.front()]<time_to_wait) {
			time_to_wait = car_times[right_bank_queue.front()];
		}

		if (time_to_wait==INT_MAX)
			time_to_wait=0;

		if (time_to_wait>global_time && ferry.size()==0) {
			global_time = time_to_wait;
		} else {
			bank = !bank;
			global_time+=t;
		}
	}
}

void TestCase::output() {
	for (vector<int>::iterator i=car_times.begin();i!=car_times.end();++i) {
		cout<<*i<<endl;
	}
}