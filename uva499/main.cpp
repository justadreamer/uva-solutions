#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main (void) {
	//init the array of frequencies:
	char A = 'A';
	char Z = 'Z';
	char a = 'a';
	char z = 'z';
	int Z_A = Z-A+1;
	int size = Z_A+z-a+1;
	int fq[size];
	string input;
	while (getline(cin,input)) {
		memset(fq,0,size*sizeof(int));
		int highest_freq = 0;
		for (size_t i=0;i<input.length();i++) {
			char cur_char=input.at(i);
			int index = 0;
			int base = 0;
			if (cur_char>=A && cur_char<=Z) {
				base = A;
			} else if (cur_char>=a && cur_char<=z) {
				base = a;
				index = Z_A;
			}	
			if (base) {
				int ind = index+cur_char-base;
				fq[ind]++;
				if (fq[ind]>highest_freq) {
					highest_freq=fq[ind];
				}
			}
		}
		if (highest_freq>0) {
			for (int i=0;i<size;i++) {
				int base = i>=Z_A ? Z_A : 0;
				if (fq[i]==highest_freq) {
					cout<<((char)(base ? 'a'+i-Z_A : 'A'+i));
				}
			}
			cout<<" "<<highest_freq<<endl;
		}
	}
	return 0;
}
