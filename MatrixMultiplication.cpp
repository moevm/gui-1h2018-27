#include "stdafx.h"

#include <cmath>

double** MultiplicationMatrix(double **a, double **b, int lsize, int msize, int nsize){ // ������� 1: l ����� � m ��������, ������� 2: m ����� � n ��������. �� ������ l ����� � n ��������

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