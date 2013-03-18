#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	string input;
	bool is_opening = true;
	while (getline(cin,input)) {
		for (int i=0;i<input.length();i++) {
			if (input.at(i) == '\"') {
				input.replace(i,1,is_opening ? "``" : "''");
				is_opening = !is_opening;
			}
		}
		cout<<input<<endl;
	}
	return 0;
}

