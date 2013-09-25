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
#include <numeric>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;

int const rows = 6;
int const cols = 5;

void input(char tab[rows][cols]) {
  for (int i=0;i<rows;++i) {
    for (int j=0;j<cols;++j) {
      cin>>tab[i][j];
    }
    cin.ignore();
  }
}

bool backtrack(int& k, int col, char password[cols], set<char> common[cols], int K) {
  if (col==cols) {
    return K==++k;
  }

  for (set<char>::iterator i = common[col].begin();i!=common[col].end();++i) {
    password[col] = *i;
    if (backtrack(k,col+1,password,common,K)) {
      return true;
    }
  }

  return false;
}

int main(int argc, char* argv[])
{
	int T;
	cin>>T; cin.ignore();

	while (T--) {
		char tab1[rows][cols];
    char tab2[rows][cols];
    int K; cin>>K; cin.ignore();
    input(tab1);
    input(tab2); 
    set<char> common[cols];
    for (int i=0;i<cols;++i) {
      for (int j=0;j<rows;++j) {
        bool is_common = false;
        for (int k=0;k<rows;++k) {
          if (tab1[j][i]==tab2[k][i]) {
            is_common = true;
            break;
          }
        }
        if (is_common) {
          common[i].insert(tab1[j][i]);
        }
      }
    }

    int k = 0;
    char password[cols];
    if (backtrack(k,0,password,common,K)) {
      for (int i=0;i<cols;++i) {
        cout<<password[i];
      }
      cout<<endl;
    } else {
      cout<<"NO"<<endl;
    }
	}
	return 0;
}