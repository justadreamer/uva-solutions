#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
struct Word {
	string orig_word;
	string sorted_word;
};

map<string,int> counts;

int main(int argc, char* argv[])
{
	string s;
	vector<Word> words;
	while (cin>>s && s!="#") {
		string sorted_word = s;
		transform(sorted_word.begin(),sorted_word.end(),sorted_word.begin(),::tolower);
		sort(sorted_word.begin(),sorted_word.end());
		counts[sorted_word]++;
		Word word = {s,sorted_word};
		words.push_back(word);
	}
	vector<string> output;
	for (int i =0;i<words.size();i++) {
		if (counts[words[i].sorted_word]==1 || words[i].orig_word.size()==1) {
			output.push_back(words[i].orig_word);
		} //this is annagram
	}

	sort(output.begin(),output.end());

	for (int i=0;i<output.size();i++) {
		cout<<output[i]<<endl;
	}

	return 0;
}