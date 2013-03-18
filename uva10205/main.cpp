#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const int N_CARDS = 52;

class NamedDeck {
public:
	NamedDeck();
	const string& operator[] (int i) {
		return card_names[i];
	}
private:
	string card_names[N_CARDS];
} named_deck;

class TestCase {
public:
	TestCase();
	static void input_blank_line();
private:
	void input();
	void output();
	void apply_shuffle(int k);
	void copy_deck(int* dst, int* src);
private:
	vector<vector<int> > shuffles;
	int deck[N_CARDS];
};

int main (void) {
	int T;
	cin>>T;
	TestCase::input_blank_line();
	for (int i=0;i<T;i++) {
		TestCase();
		if (i<T-1)
			cout<<endl;
	}
	return 0;
}

TestCase::TestCase() {
	input();
	output();
}

void TestCase::input_blank_line() {
	string blank;
	getline(cin,blank);
}

void TestCase::input() {
	//creating new deck
	for (int i=0;i<N_CARDS;i++) {
		deck[i] = i;
	}

	int n; //number of shuffles
	cin>>n;
	for (int i=0;i<n;i++) {
		vector<int> shuffle(N_CARDS);
		for (int j=0;j<N_CARDS;j++) {
			int index;
			cin >> index;
			shuffle[j]=index-1;
		}
		shuffles.push_back(shuffle);
	}

	string input_s;
	getline(cin,input_s);//endl
	while(getline(cin,input_s) && input_s.length()>0) {
		int k;
		stringstream(input_s)>>k;
		k--;
		apply_shuffle(k);
	}
}

void TestCase::apply_shuffle(int k) {
	vector<int>& shuffle = shuffles.at(k);
	int new_deck[N_CARDS];
	for (int j=0;j<N_CARDS;j++) {
		int i=shuffle[j];
		//i in position j means that the shuffle moves the ith card in the deck to position j.
		new_deck[j]=deck[i];
	}
	copy_deck(deck,new_deck);
}

void TestCase::copy_deck(int* dst,int* src) {
	for (int i=0;i<N_CARDS;i++) {
		dst[i]=src[i];
	}
}

void TestCase::output() {
	for (int i=0;i<N_CARDS;i++) {
		cout<<named_deck[deck[i]]<<endl;
	}
}

NamedDeck::NamedDeck() {
	const int N_SUITS = 4;
	static const char* SUITS[] = {"Clubs","Diamonds","Hearts","Spades"};
	static const char* CARDS[] = {"Jack","Queen","King","Ace"};
	const int suit_length = N_CARDS/N_SUITS;
	for (int i=0;i<N_SUITS;i++) {
		for (int j=2;j<=suit_length+1;j++) {
			stringstream name_stream(ios_base::out);
			if (j<=10) {
				name_stream << j;
			} else {
				name_stream << CARDS[j-11];
			}
			name_stream << " of " << SUITS[i];
			card_names[i*suit_length+j-2]=name_stream.str();
		}
	}
}
