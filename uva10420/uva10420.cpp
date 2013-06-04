#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<string,int> simap;

int main (void) {
	string input;
	int N;
	cin>>N;
	simap beauties;
	for (int i=0;i<N;i++) {
		string input;
		cin>>input;
		beauties[input]++;
		getline(cin,input);
	}
	for (simap::iterator it=beauties.begin();it!=beauties.end();it++) {
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
