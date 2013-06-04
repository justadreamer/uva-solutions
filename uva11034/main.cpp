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
	int l,m,times;
	vector<int> car_sizes;
	queue<int> left_bank_queue;
	queue<int> right_bank_queue;
};

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
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
	cin>>l>>m;
	l*=100;
	for (int i=0;i<m;++i) {
		int time;
		string bank;
		cin>>time>>bank;
		car_sizes.push_back(time);

		if (bank==LEFT) {
			left_bank_queue.push(i);
		} else if (bank==RIGHT) {
			right_bank_queue.push(i);
		}
	}

	times = 0;
}

void TestCase::calc() {
	int delivered = 0;
	queue<int> ferry;
	int bank = left_bank;
	bool condition = false;
	do {
		queue<int>& this_bank_queue = bank==left_bank ? left_bank_queue : right_bank_queue;
		while (ferry.size()) {
			ferry.pop();
			++delivered;
		}

		int total_length = 0;
		while (this_bank_queue.size() && total_length+car_sizes[this_bank_queue.front()]<l) {
			total_length+=car_sizes[this_bank_queue.front()];
			ferry.push(this_bank_queue.front());
			this_bank_queue.pop();
		}

		condition = ferry.size() || left_bank_queue.size() || right_bank_queue.size();
		if (condition) {
			bank = !bank;
			++times;
		}
	} while (condition);
}

void TestCase::output() {
	cout<<times<<endl;
}