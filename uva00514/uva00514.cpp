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

using namespace std;

int main(int argc, char* argv[])
{
	int N;
	while (cin>>N && N) {
		int first_coach = 0;
		while (cin>>first_coach && first_coach) {
			//input:
			vector<int> train(N,first_coach);
			for (int i=1;i<N;++i) {
				int coach;
				cin>>coach;
				train[i]=coach;
			}

			//calculation:
			stack<int> station;
			int counter=1;
			bool success=true;
			for (int i=0;i<N;++i) {
				int coach = train[i];
				while (counter<=coach) {
					station.push(counter++);
				}
				if (station.top()!=coach) {
					success=false;
					break;
				}
				station.pop();
			}

			//output:
			cout<<(success ? "Yes" : "No")<<endl;
		}
		cout<<endl;
	}
	return 0;
}