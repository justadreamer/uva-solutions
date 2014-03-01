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

#include <stdio.h>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;


/* //for primes precalc:
void gen_primes(int n) {
  vi primes;
  for (int i=2;i<=n;++i) {
    bool is_prime = true;
    for (int j=0;j<primes.size();++j) {
      if (i % primes[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) primes.push_back(i);
  }

  cout<<"int primes [] = {";
  for (int i=0;i<primes.size();++i) {
    if (i>0) cout<<",";
    cout<<primes[i];
  }
  cout<<"};";
}
*/

int primes [] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117};
int n_primes = sizeof(primes)/sizeof(primes[0]);


vi a(14+1,-1);
vector<vi> b(1120+1,a);
vector<vector<vi> > memo (n_primes,b);

int value (int id, int n, int k) {
  if (id==n_primes || k<=0 || n<=0) return 0;
  if (memo[id][n][k]>-1) return memo[id][n][k];
  if (primes[id]>n) return memo[id][n][k]=0;
  if (primes[id]==n && k==1) return memo[id][n][k]=1;
  return memo[id][n][k] = value(id+1,n-primes[id],k-1) + value(id+1,n,k);
}

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif
  int n,k;

	while (cin>>n>>k && n && k) {
		cout<<value(0,n,k)<<endl;
	}
	return 0;
}