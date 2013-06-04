#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;
const int N_CARDS=52;

class TestCase {
public:
	TestCase();
	TestCase(int _n);
	static void input_blank_line();
private:
	void input();
	void output();
	void calc();
	int card_value(const string& card);
private:
	vector<string> cards;
	int n;
	string card;
};

int main (void) {
	int T;
	cin >> T;

	for (int i=0;i<T;i++) {
		TestCase testCase(i);
	}
	return 0;
}

TestCase::TestCase() {

}

TestCase::TestCase(int _n):n(_n) {
	input();
	calc();
	output();
}

void TestCase::input() {
	for (int i=0;i<N_CARDS;i++) {
		string card;
		cin>>card;
		cards.push_back(card);
	}
}

void TestCase::calc() {
	reverse(cards.begin(),cards.end());
	vector<string> top_25(cards.begin(),cards.begin()+25);
	cards.erase(cards.begin(),cards.begin()+25);
	int Y = 0;
	for (int i=0;i<3;i++) {
		int X = card_value(cards.front());
		Y+=X;
		cards.erase(cards.begin(),cards.begin()+1+10-X);
	}
	cards.insert(cards.begin(),top_25.begin(),top_25.end());
	card = cards[cards.size()-Y];
}

int TestCase::card_value(const string& card) {
	int v=0;
	stringstream(card)>>v;
	v = v ? v : 10;
	return v;
}
void TestCase::output() {
	cout<<"Case "<<n+1<<": "<<card<<endl;
}
