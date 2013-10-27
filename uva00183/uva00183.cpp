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
typedef set<int> si;

string split_by_50(const string& s) {
  string ns; int prev=0;
  if (s.size()>50) {
    for (int i=0;i<s.size();++i) {
      if (i>0 && i % 50==0 && i<s.size()-1) {
        ns+=s.substr(prev,i-prev)+"\n";
        prev=i;
      } else if (i==s.size()-1) {
        ns+=s.substr(prev,i-prev+1);
      }
    }
  }
  return ns.size() ? ns : s;
}

string to_D(int row, int col, int m, int n, vector<vi>& rows) {
  string s = "";
  if (m==0 || n==0) {
    return s;
  }
  int common = rows[row][col];
  bool same = true;
  for (int i=row;i<row+m;++i) {
    for (int j=col;j<col+n;++j) {
      if (rows[i][j]!=common) {
        same = false;
        break;
      }
    }
  }
  if (same) {
    s = common == 1 ? "1" : "0";
  } else {
    int top = m / 2 + m % 2;
    int left = n / 2 + n % 2;
    s = "D" + to_D(row,col,top,left,rows) + to_D(row,col+left,top,n-left,rows) +
              to_D(row+top,col,m-top,left,rows) + to_D(row+top,col+left,m-top,n-left,rows);
  }
  return s;
}

string to_D(int m, int n, const string& bitmap) {
  vector<vi> rows(m);
  for (int i=0;i<m;++i) {
    for (int j=0;j<n;++j) {
      rows[i].push_back(bitmap[i*n+j]-'0');
    }
  }

  return split_by_50(to_D(0,0,m,n,rows));
}

void fill(int row, int col, int m, int n, vector<vi>& rows,int f) {
  for (int i=row;i<row+m;++i) {
    for (int j=col;j<col+n;++j) {
      rows[i][j]=f;
    }
  }
}

void to_B(int row,int col,int m, int n, vector<vi>& rows, string& bitmap) {
  if (m==0 || n==0)
    return;
  int f = -1;
  if (bitmap[0]=='0') {
    f = 0;
  } else if (bitmap[0]=='1') {
    f = 1;
  }

  bitmap=bitmap.substr(1);
  if (f>=0) {
    fill(row,col,m,n,rows,f);
  } else {
    int top = m / 2 + m % 2;
    int left = n / 2 + n % 2;
    to_B(row,col,top,left,rows,bitmap);
    to_B(row,col+left,top,n-left,rows,bitmap);
    to_B(row+top,col,m-top,left,rows,bitmap);
    to_B(row+top,col+left,m-top,n-left,rows,bitmap);
  }
}

string to_B(int m, int n, string& bitmap) {
  vector<vi> rows(m);
  for (int i=0;i<m;++i) {
    for (int j=0;j<n;++j) {
      rows[i].push_back(0);
    }
  }
  to_B(0,0,m,n,rows,bitmap);
  string s(m*n,' ');
  for (int i=0;i<m;++i) {
    for (int j=0;j<n;++j) {
      s[i*n+j]=rows[i][j]+'0';
    }
  }

  return split_by_50(s);
}

int main(int argc, char* argv[])
{
  char c;
	int m,n;
  int state = 0; //0==regular input; 1==bitmap data input; 2==processing of bitmap, transition to regular input;
  string input;
  string bitmap;
	while (true) {
    if (state==2) {
      //we don't read line in this state, it has been read on a previous loop
      state = 0;
      if (c=='B') {
        cout<<"D"<<setw(4)<<m<<setw(4)<<n<<endl;
        cout<<to_D(m,n,bitmap)<<endl;
      } else if (c=='D') {
        cout<<"B"<<setw(4)<<m<<setw(4)<<n<<endl;
        cout<<to_B(m,n,bitmap)<<endl;
      }
    } else {
      //in any other state we first read line
      getline(cin,input);
    }
    
    if (state==0) {
      c = input[0];
      if (c=='#') {
        break;
      } else {
        sscanf(input.c_str(),"%c %d %d",&c,&m,&n);
        state = 1; //we start reading line
        bitmap="";
      }
    } else if (state==1) {
      //here we analyze input whether it belongs to bitmap data, or is it just the next line of other input
      if (input[0]=='#' || input[1]==' ') {
        state = 2;
      } else {
        bitmap+=input;
      }
    }
	}
	return 0;
}