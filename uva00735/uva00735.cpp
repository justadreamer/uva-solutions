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
#include <bitset>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;

int main(int argc, char* argv[]) {
  set<int> scores_set;
  scores_set.insert(0);
  for (int i=1;i<=20;++i) {
    scores_set.insert(i);
    scores_set.insert(i*2);
    scores_set.insert(i*3);
  }
  scores_set.insert(50);
  vi scores;
  for (set<int>::iterator i=scores_set.begin();i!=scores_set.end();++i) {
    scores.push_back(*i);
  }

  int score;
	while (cin>>score && score>0) {
    set<set<int> > combinations;

		for (int a=0;a<scores.size() && scores[a]<=score;++a) {
      for (int b=0;b<scores.size() && scores[b]<=score-scores[a];++b) {
        for (int c=0;c<scores.size() && scores[c]<=score-scores[a]-scores[b];++c) {
          if (scores[a]+scores[b]+scores[c]==score) {
            set<int> combination;
            combination.insert(a); combination.insert(b); combination.insert(c);
            combinations.insert(combination);
          }
        }
      }
    }
    int permutations=0;
    for (set<set<int> >::iterator i = combinations.begin();i!=combinations.end();++i) {
      if ((*i).size()==1) {
        permutations++;
      } else if ((*i).size()==2) {
        permutations+=3;
      } else if ((*i).size()==3) {
        permutations+=6;
      }
    }
    if (combinations.size()>0) {
      cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<score<<" IS "<<combinations.size()<<"."<<endl;
      cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<score<<" IS "<<permutations<<"."<<endl;
    } else {
      cout<<"THE SCORE OF "<<score<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
    }
    for (int i=0;i<70;++i) cout<<"*";
    cout<<endl; 
	}
  cout<<"END OF OUTPUT"<<endl;

	return 0;
}