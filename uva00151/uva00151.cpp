#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int W = 13;
int FREE = 0;
int OCCUPIED = 1;

void init_array(int* arr, int size) {
	for (int n=0;n<=size;n++) {
		arr[n]=FREE;
	}
}

bool walk_array(int* arr, int size, int step, int wellington) {
	int covered = 0;
	int cur=1;
	int N = size;
	while (covered<N) {		
		if (arr[cur]==FREE) {
			arr[cur]=OCCUPIED;
			covered++;
			if (cur==wellington && covered<N)
				return false;
		}

		int free_counter=0;
		while (covered<N && free_counter<step) {
			cur=(cur+1)%(N+1); if (cur==0) cur=1;
			if (arr[cur]==FREE) {
				free_counter++;
			}
		}
	}
	return true;
}

int determine_min_step(int N) {
	int* arr = new int[N+1];

	int res = 0;
	for (int m=1;m<=N;m++) {
			//LET'S TRY EVERY m:
		init_array(arr,N);
		if (walk_array(arr,N,m,W)) {
			res = m;
			break;
		}
	}

	delete [] arr;
	return res;
}

int main(int argc, char* argv[])
{
	int N = 0;
	while (cin>>N && N>0) {
		cout<<determine_min_step(N)<<endl;
	}
	return 0;
}
