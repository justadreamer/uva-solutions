#include <iostream>
#include <string>

using namespace std;


int main (void) {
	int N;
	while (cin>>N) {
		int B,H,W;
		cin>>B>>H>>W;
		int min_price=B+1;
		for (int h=0;h<H;h++) {
			int p;
			cin>>p;
			for (int w=0;w<W;w++) {
				int b;
				cin>>b;
				if (b>=N) {
					int price = p*N;
					if (price<min_price) {
						min_price=price;
					}
				}
			}
		}
		if (min_price<=B) {
			cout<<min_price;
		} else {
			cout<<"stay home";
		}
		cout<<endl;
	}
	return 0;
}
