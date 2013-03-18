#include <iostream>
#include <string>

using namespace std;


int main (void) {
	int T;
	cin >> T;
	for (int c=1;c<=T;c++) {
		int N;
		cin >> N;
		int max = 0;
		for (int i=0;i<N;i++) {
			int v;
			cin >> v;
			if (v>max) {
				max=v;
			}
		}
		cout<<"Case "<<c<<": "<<max<<endl;
	}
	return 0;
}
