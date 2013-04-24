#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;
const int SEC = 1;
const int MIN = 60 * SEC;
const int HOUR = 60 * MIN;
const int yellow = 5;

const char* fail_message = "Signals fail to synchronise in 5 hours";

struct Range {
	int start;
	int end;
	Range():start(0),end(0) {

	}
	Range(int _start, int _end) : start(_start),end(_end) {

	}

	int length() {
		return end - start;
	}

	void print_hh_mm_ss () {
		int t = start;
		int hh = t / HOUR;
		int mm = (t-hh*HOUR) / MIN;
		int ss = (t-hh*HOUR-mm*MIN) / SEC;
		printf("%02d:%02d:%02d\n",hh,mm,ss);
	}

	void print () {
		cout<<start<<"-"<<end<<endl;
	}
};

Range intersect (const Range& r,int cycle_time) {
	//full cycles green+red before the r.start:
	Range intersection;

	int full_cycle = 2*cycle_time;
	int cycles = r.start / full_cycle;
	int green_length = cycle_time-yellow;

	int closest_green_start = cycles  * full_cycle;
	int closest_green_end = closest_green_start+green_length;
	int next_green_start = (cycles + 1) * full_cycle;
	int next_green_end = next_green_start+green_length;

	if (r.start <= closest_green_end && closest_green_end <= r.end) {
		intersection.start = r.start;
		intersection.end = closest_green_end;
	} else if (closest_green_end > r.end) {
		intersection.start = r.start;
		intersection.end = r.end;
	} else if (r.start<=next_green_start && next_green_start<=r.end) {
		intersection.start = next_green_start;
		intersection.end = min(next_green_end,r.end);
	}

	return intersection;
}

void process_scenario(vector<int>& cycle_times) {
	int current_time = 0;
	sort(cycle_times.begin(),cycle_times.end());
	while (current_time<5*HOUR) {
		current_time+=2*cycle_times[0];
		Range range (current_time,current_time+cycle_times[0]-yellow);
		for (int i=1;i<cycle_times.size() && range.length()>0;++i) {
			range = intersect(range,cycle_times[i]);
		}
		if (range.length()>0) {
			range.print_hh_mm_ss();
			return;
		}
	}
	cout<<fail_message<<endl;
}

int main(int argc, char* argv[])
{
	vector<int> cycle_times;
	int zero_count = 0;
	while (true) {
		int t = 0;
		cin>>t;
		if (t==0) {
			if (zero_count==0) {
				process_scenario(cycle_times);
				cycle_times.clear();
			}
			zero_count++;
			if (zero_count>3) {
				break;
			}
		} else {
			zero_count=0;
			cycle_times.push_back(t);
		}
	}
	return 0;
}