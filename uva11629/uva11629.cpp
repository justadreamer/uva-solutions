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
bool is_comparison(const string& token) {
	return token==">" || token=="<" || token== ">=" || token == "<=" || token=="=";
}

bool compare(int percentage,int guess,const string& token) {
	if (token==">") {
		return percentage > guess;
	} else if (token=="<") {
		return percentage < guess;
	} else if (token==">=") {
		return percentage >= guess;
	} else if (token=="<=") {
		return percentage <= guess;
	} else if (token=="=") {
		return percentage == guess;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int p,g;
	cin>>p>>g;
	map<string,int> votes;
	for (int i=0;i<p;++i) {
		string party;
		float percent;
		cin>>party>>percent;
		votes[party]=round(percent*10.0);
	}
	cin.ignore();
//evaluating guesses:
	
	for (int i=0;i<g;++i) {
		string guess;
		getline(cin,guess);
		stringstream ss(guess);
		string token;
		int percentage=0;

		while (ss>>token) {
			if (token=="+") {
				//skip
			} else if (is_comparison(token)) {
				int num;
				ss>>num;
				num*=10;
				cout<<"Guess #"<<i+1<<" was ";
				if (!compare(percentage,num,token)){
					cout<<"in";
				}
				cout<<"correct."<<endl;
				break;
			} else {
				percentage+=votes[token];
			}
		}
	}
	return 0;
}
