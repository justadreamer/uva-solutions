#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const int N_CELLS = 100;
const int LAST_CELL = N_CELLS-1;
class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
private:
	int n_players,n_snakes,n_rolls;
	int transitions[N_CELLS];
	vector<int> positions;
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
	for (int i=0;i<N_CELLS;i++) {
		transitions[i]=i;
	}
	input();
	calc();
	output();
}

void TestCase::input() {
	cin>>n_players>>n_snakes>>n_rolls;
	for (int i=0;i<n_players;i++) {
		positions.push_back(0);
	}
	for (int i=0;i<n_snakes;i++) {
		int mouth,tail;
		cin>>mouth>>tail;
		transitions[mouth-1]=tail-1;
	}
	int cur_player=0;
	bool is_game_finished = false;
	for (int i=0;i<n_rolls;i++) {
		int roll;
		cin>>roll;
		if (is_game_finished)
			continue;

		int new_pos = positions[cur_player]+roll;
		while (new_pos<LAST_CELL && transitions[new_pos]!=new_pos) {
			new_pos=transitions[new_pos];
		}
		if (new_pos >= LAST_CELL) {
			new_pos = LAST_CELL;
			is_game_finished = true;
		}
		positions[cur_player] = new_pos;
		cur_player = (cur_player+1) % n_players;
	}
}

void TestCase::output() {
	for (int i=0;i<positions.size();i++) {
		cout<<"Position of player "<<i+1<<" is "<<positions[i]+1<<"."<<endl;
	}
}

void TestCase::calc() {
	
}