#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;


int main(int argc, char* argv[])
{
	int hh=0,mm=0;
	double coef_h = 360.0/12.0;
	double coef_m = 360.0/60.0;
	while (scanf("%d:%02d",&hh,&mm) && (hh || mm)) {
		double h_angle = coef_h*((double)hh+((double)mm)/60.0);
		double m_angle = coef_m*((double)mm);

		double max_angle = max(h_angle,m_angle);
		double min_angle = min(h_angle,m_angle);

		double diff = max_angle -min_angle;
		if (diff>180.0) {
			diff = 360.0-max_angle+min_angle;
		}

		printf("%.03f\n",diff);
	}
	return 0;
}