#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double r;
	
	scanf(" %lf", &r);
	r = r * r;
	printf("%.6f\n%f\n", r * M_PI, r * 2);
}