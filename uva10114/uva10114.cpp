#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>
#include <set>

using namespace std;

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
private:
};

int main(int argc, char* argv[])
{
	bool exit = false;
	while (true) {
		//input:
		int months;
		double downpayment;
		double loan;
		int n;
		cin>>months;
		if (months<0)
			break;
		cin>>downpayment>>loan>>n;
		vector<double> depreciations(months+1,0);

		for (int i=0;i<n;i++) {
			int month;
			double depreciation;
			cin>>month>>depreciation;
			depreciations[month]=depreciation;
			//if (month>0) {
				for (int j=month;j<=months;j++) {
					depreciations[j]=depreciation;
				}
			//}
		}

		//calculation:
		double cost = loan + downpayment;
		double monthly_amount = loan/(double)months;
		int result = 0;
		for (int i=0;i<=months;i++) {
			cost -= cost*depreciations[i];
			double owed = loan - i*monthly_amount;
			//cout<<"i="<<i<<" ows="<<owed<<" cost="<<cost<<endl;
			if (owed < cost) {
				result = i;
				break;
			}
		}
		cout<<result<<" "<<(result==1 ? "month" : "months")<<endl;
	}
	return 0;
}