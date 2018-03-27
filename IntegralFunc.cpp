#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

double value_at_a_point(string string, int& counter, double x, int& brct, bool& error);

double Integral(string string, double a, double b){
	bool error = false;
	double res = 0;
	int counter = 0;
	int brct = 0;
	double help1, help2, help3;
	const int n = 10000; // количество точек. Влияет на скорость работы.
	double x[n+1] = { 0 };
	x[0] = a;
	double h = (b - a) / n;
	for (int i = 1; i < n+1 ; ++i){
		x[i] = x[i - 1] + h;
	}
	for (int k = 1; k < n; k = k + 2){	
		counter = 0;
		brct = 0;
		help1 = value_at_a_point(string, counter, x[k - 1], brct, error);
		if (error) return -1000; // error
		counter = 0;
		brct = 0;
		help2 = value_at_a_point(string, counter, x[k], brct, error);
		counter = 0;
		brct = 0;
		help3 = value_at_a_point(string, counter, x[k + 1], brct, error);
		res = res + help1 + 4 * help2 + help3;
	}
	res = res * h / 3;
	return res;
}