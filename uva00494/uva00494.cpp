#include <iostream>
#include <string>

using namespace std;


int main (void) {
	string input;
	while (getline(cin,input)) {
		bool is_word = false;
		int word_count = 0;
		for (size_t i=0;i<input.length();i++) {
			char cur_char=input.at(i);
			if (cur_char>='A' && cur_char<='Z' || cur_char>='a' && cur_char<='z') {
				if (!is_word) {
					word_count++;
					is_word=true;
				}
			} else {
				is_word=false;
			}
		}
		cout<<word_count<<endl;
	}
	return 0;
}
