#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>

using namespace std;

typedef vector<int> vi;
struct triple {
	int& operator[](int i) {return t[i];}
private:
	int t[3];
};


int main(int argc, char* argv[])
{
	int n,m;
	while (true) {
		cin>>n>>m;
		if (n==0 && m==0)
			break;

		vector<triple> constraints;
		
		for (int i=0;i<m;++i) {
			triple constraint;
			cin>>constraint[0]>>constraint[1]>>constraint[2];
			constraints.push_back(constraint);
		}

		vi permutation;
		for (int i=0;i<n;++i) {
			permutation.push_back(i);
		}

		int count=0;

		do {
			bool all_constraints_satisfied = true;
			for (vector<triple>::iterator t=constraints.begin();t!=constraints.end();++t) {
				triple& tr = *t;
				vi::iterator pos1 = find(permutation.begin(),permutation.end(),tr[0]);
				vi::iterator pos2 = find(permutation.begin(),permutation.end(),tr[1]);
				int dist = abs(distance(pos1,pos2));
				bool cond = (tr[2]<0 && dist>=abs(tr[2])) || 
					(tr[2]>0 && dist<=tr[2]);

				if (!cond) {
					all_constraints_satisfied = false;
					break;
				}
			}

			if (all_constraints_satisfied) 
				++count;
		} while (next_permutation(permutation.begin(),permutation.end()));

		cout<<count<<endl;
	}

	return 0;
}