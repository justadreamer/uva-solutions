#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

const int MAX_FRAMES = 10;
const char STRIKE = 'X';
const char SPARE = '/';
const int STRIKE_SCORE = 10;

int to_score(char rolls[],int i) {
	int score = 0;
	if (rolls[i]==STRIKE) {
		score = STRIKE_SCORE;
	} else if (rolls[i]==SPARE) {
		score = STRIKE_SCORE-to_score(rolls,i-1);
	} else {
		score = rolls[i]-'0';
	}
	return score;
}

int calc (string& input) {
	stringstream s(input);
	char rolls[MAX_FRAMES*2+1];

	int roll_count=0;
	while (s>>rolls[roll_count++]) {};
	roll_count--;
	int score = 0;
	int frame_count = 0;
	int roll = 0;
	for (int i=0;i<roll_count && frame_count<MAX_FRAMES;i++) {
		char c = rolls[i];
		roll++;
		score+=to_score(rolls,i);
		if (c==SPARE) {
			score+=to_score(rolls,i+1);
		} else if (c==STRIKE) {
			score+=to_score(rolls,i+1);
			score+=to_score(rolls,i+2);
			roll=0;
		}
		roll%=2;
		if (0==roll) {
			frame_count++;
		}
	}
	return score;
}

const string GAME_OVER = "Game Over";

int main(int argc, char* argv[])
{
	string input;
	while (getline(cin,input) && input!=GAME_OVER) {
		cout<<calc(input)<<endl;
	}
	return 0;
}