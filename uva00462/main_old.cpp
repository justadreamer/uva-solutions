#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;
#define ARR_SIZE(X) sizeof(X)/sizeof(X[0])
char SUITS[] = {'S','H','D','C'};
const int N_SUITS = ARR_SIZE(SUITS);
int suit_to_ind(char s);

int main (void) {
	string input;
	while (getline(cin,input)) {
		stringstream sinput(input);
		string card;
		vector<char> suit[N_SUITS];
		int suit_points[N_SUITS];
		bool is_suit_stopped[N_SUITS];
		//initalization
		for (int i=0;i<N_SUITS;i++) {
			suit_points[i]=0;
			is_suit_stopped[i]=false;
		}

		//reading input
		while (sinput>>card) {
			suit[suit_to_ind(card.at(1))].push_back(card.at(0));
		}

		//calculating the points
		int points = 0;
		int intermediate_points = 0;
		for (int i=0;i<N_SUITS;i++) {
			for (vector<char>::iterator it=suit[i].begin();it<suit[i].end();it++) {
				
				//1. Each ace counts 4 points. Each king counts 3 points. Each queen counts 2 points. Each jack
				//counts one point.
				switch (*it) {
					case 'A': {
								  suit_points[i]+=4;
								  //A suit is stopped if it contains an ace, or if it contains a king and at least one other card, or if it
								  //contains a queen and at least two other cards.
								  is_suit_stopped[i]=true;
							  } break;
					case 'K': {
								  suit_points[i]+=3;
								 //2. Subtract a point for any king of a suit in which the hand holds no other cards.
								  if (suit[i].size()==1) {
								  	suit_points[i]--;
								  } else {
								  	is_suit_stopped[i]=true;
								  }
							  } break;
					case 'Q': {
								  suit_points[i]+=2;
								//3. Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.
								 if (suit[i].size()<=2) {
								  	suit_points[i]--;
								  } else {
								  	is_suit_stopped[i]=true;
								  }
							  } break;
					case 'J': {
								  suit_points[i]+=1;
								  //4. Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards
								  if (suit[i].size()<=3) {
								  	suit_points[i]--;
								  }
							  } break;
				}
			}
			
			points+=suit_points[i];
			intermediate_points+=suit_points[i];

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
		
		//If the hand evaluates to fewer than 14 points, then the player must pass.
		if (points<14) {
			cout<<"PASS"<<endl;
			continue;
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
				continue;
			}
		}

		//One may open bidding in a suit if the hand evaluates to 14 or more points. Bidding is always opened in one of the suits with the most cards.
		int max_cards = 0;
		char res_suit = SUITS[0];
		for (int i=0;i<N_SUITS;i++) {
			if (suit[i].size()>max_cards) {
				max_cards = suit[i].size();
				res_suit = SUITS[i];
			}
		}

		cout<<"BID "<<res_suit<<endl;
	}
	return 0;
}

int suit_to_ind(char s) {
	for (int i=0;i<N_SUITS;i++) {
		if (SUITS[i]==s) {
			return i;
		}
	}
	return 0;
}
