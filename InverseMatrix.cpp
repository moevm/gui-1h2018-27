#include "stdafx.h"

#include <cmath>

double matrixDet(double **matrix, int size);

double** InverseMatrix(double **a, double **b, bool &error, int size){
	double chast = 0;
	double mnoj = 0;
	double **c = new double*[size];
	for (int i = 0; i < size; i++) { // ед матрица
		c[i] = new double[size];
	}

	for (int i = 0; i < size; i++){ // ед матрица
		for (int k = 0; k < size; ++k){
			if (i == k) c[i][k] = 1;
			else c[i][k] = 0;
		}
	}
	if (matrixDet(a, size) == 0){
		error = true;
		return a;
	}
	else{
		for (int gli = 0; gli < size; ++gli){
			chast = a[gli][gli];
			for (int k = 0; k < size; ++k){
				c[gli][k] = c[gli][k] / chast;
				a[gli][k] = a[gli][k] / chast;
			}
			for (int k = 0; k < size; ++k){
				if (k != gli){
					mnoj = a[k][gli];
					for (int l = 0; l < size; ++l){
						a[k][l] = a[k][l] - a[gli][l] * mnoj;
						c[k][l] = c[k][l] - c[gli][l] * mnoj;
					}
				}
			}
		}
	}
	b = c;
	return b;
}