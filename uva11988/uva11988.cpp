#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>
#include <set>
#include <list>

using namespace std;

list<char> line;
list<char>::iterator pos;

void output() {
	for (list<char>::iterator i=line.begin();i!=line.end();++i) {
		cout<<*i;
	}
	cout<<endl;
	line.clear();
	pos = line.end();
}

int main(int argc, char* argv[])
{
	char c;
	pos = line.end();
	while ((c=cin.get()) && cin) {
		if (c=='\n') {
			output();
			continue;
		} else if (c=='[') {
			pos = line.begin();
		} else if (c==']') {
			pos = line.end();
		} else {
			pos = line.insert(pos,c);
			++pos;
		}
	}
	if (line.size()) {
		output();
	}

	return 0;
}