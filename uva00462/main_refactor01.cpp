#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

#define ARR_SIZE(X) sizeof(X)/sizeof(X[0])

char SUIT[] = {'S','H','D','C'};
const int N_SUITS = ARR_SIZE(SUIT);

int suit_to_ind(char s);
void read_input(string& input,vector<char> suit[]);
void calculate_points(vector<char> suit[],bool is_suit_stopped[], int& points, int& intermediate_points);
void output(vector<char> suit[],bool is_suit_stopped[], int points, int intermediate_points);

int main (void) {
	string input;
	while (getline(cin,input)) {
		vector<char> suit[N_SUITS];
		read_input(input,suit);

		//calculating the points
		int points = 0;
		int intermediate_points = 0;
		bool is_suit_stopped[N_SUITS];
		//initalization of is_suit_stopped
		for (int i=0;i<N_SUITS;i++) {
			is_suit_stopped[i]=false;
		}

		calculate_points(suit,is_suit_stopped,points,intermediate_points);

		output(suit,is_suit_stopped,points,intermediate_points);
	}

	return 0;
}

int suit_to_ind(char s) {
	for (int i=0;i<N_SUITS;i++) {
		if (SUIT[i]==s) {
			return i;
		}
	}
	return 0;
}

void read_input(string& input, vector<char> suit[]) {
	stringstream sinput(input);
	string card;
	while (sinput>>card) {
		int suit_ind = suit_to_ind(card.at(1));
		char card_value = card.at(0);
		suit[suit_ind].push_back(card_value);
	}
}

void calculate_points(vector<char> suit[],bool is_suit_stopped[], int& points, int& intermediate_points) {
	for (int i=0;i<N_SUITS;i++) {
		int per_suit_points = 0;
		for (vector<char>::iterator it=suit[i].begin();it<suit[i].end();it++) {
			
			//1. Each ace counts 4 points. Each king counts 3 points. Each queen counts 2 points. Each jack
			//counts one point.
			switch (*it) {
				case 'A': {
							  per_suit_points+=4;
							  //A suit is stopped if it contains an ace, or if it contains a king and at least one other card, or if it
							  //contains a queen and at least two other cards.
							  is_suit_stopped[i]=true;
						  } break;
				case 'K': {
							  per_suit_points+=3;
							  //2. Subtract a point for any king of a suit in which the hand holds no other cards.
							  if (suit[i].size()==1) {
							  	per_suit_points--;
							  } else {
							  	is_suit_stopped[i]=true;
							  }
						  } break;
				case 'Q': {
							  per_suit_points+=2;
							  //3. Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.
							 if (suit[i].size()<=2) {
							  	per_suit_points--;
							  } else {
							  	is_suit_stopped[i]=true;
							  }
						  } break;
				case 'J': {
							  per_suit_points+=1;
							  //4. Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards
							  if (suit[i].size()<=3) {
							  	per_suit_points--;
							  }
						  } break;
			}
		}
	
		intermediate_points+=per_suit_points;
		points+=per_suit_points;
		//5. Add a point for each suit in which the hand contains exactly two cards.
		if (suit[i].size()==2) {
			points++;
		}
		//6. Add two points for each suit in which the hand contains exactly one card.
		//7. Add two points for each suit in which the hand contains no cards.
		if (suit[i].size()==1 || suit[i].size()==0) {
			points+=2;
		}
	}
}

void output(vector<char> suit[],bool is_suit_stopped[], int points, int intermediate_points) {
	//If the hand evaluates to fewer than 14 points, then the player must pass.
	if (points<14) {
		cout<<"PASS"<<endl;
		return;
	}

	//One may open bidding in \no trump" if the hand evaluates to 16 or more points ignoring rules 5,
	//6, and 7 and if all four suits are stopped. A no trump bid is always preferred over a suit bid when
	//both are possible.}

	if (intermediate_points>=16) {
		bool is_all_stopped = true;
		for (int i=0;i<N_SUITS;i++) {
			if (!is_suit_stopped[i]) {
				is_all_stopped=false;
				break;
			}
		}

		if (is_all_stopped) {
			cout<<"BID NO-TRUMP"<<endl;
			return;
		}
	}

	//One may open bidding in a suit if the hand evaluates to 14 or more points. Bidding is always opened in one of the suits with the most cards.
	int max_cards = 0;
	char res_suit = SUIT[0];
	for (int i=0;i<N_SUITS;i++) {
		if (suit[i].size()>max_cards) {
			max_cards = suit[i].size();
			res_suit = SUIT[i];
		}
	}

	cout<<"BID "<<res_suit<<endl;
}