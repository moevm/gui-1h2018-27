#include "stdafx.h"

#include <cmath>

double** MultiplicationMatrix(double **a, double **b, int lsize, int msize, int nsize){ // матрица 1: l строк и m столбцов, матрица 2: m строк и n столбцов. На выходе l строк и n столбцов

	double **c = new double*[nsize];
	for (int i = 0; i < nsize; i++) { 
		c[i] = new double[lsize];
	}

	for (int i = 0; i < lsize; i++) {
		for (int l = 0; l < nsize; l++) {
			double s = 0;
			for (int j = 0; j < msize; j++) {
				s += a[i][j] * b[j][l];
			}
			c[i][l] = s;
		}
	}

	return c;
}