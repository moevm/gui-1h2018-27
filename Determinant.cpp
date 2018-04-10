#include "stdafx.h"

void getMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double **newMatrix) {
	int offsetRow = 0; //�������� ������� ������ � �������
	int offsetCol = 0; //�������� ������� ������� � �������
	for (int i = 0; i < size - 1; i++) {
		//���������� row-�� ������
		if (i == row) {
			offsetRow = 1; //��� ������ ��������� ������, ������� ���� ����������, ������ �������� ��� �������� �������
		}

		offsetCol = 0; //�������� �������� �������
		for (int j = 0; j < size - 1; j++) {
			//���������� col-�� �������
			if (j == col) {
				offsetCol = 1; //��������� ������ �������, ��������� ��� ���������
			}
			newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
		}
	}
}


double matrixDet(double **matrix, int size) {
	double det = 0;
	int degree = 1; 


	if (size == 1) {
		return matrix[0][0];
	}
	else if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else {
		//������� ��� ������ � �������
		double **newMatrix = new double*[size - 1];
		for (int i = 0; i < size - 1; i++) {
			newMatrix[i] = new double[size - 1];
		}

		//������������ �� 0-�� ������, ���� ����� �� ��������
		for (int j = 0; j < size; j++) {
			//������� �� ������� i-� ������ � j-�� �������
			//��������� � newMatrix
			getMatrixWithoutRowAndCol(matrix, size, 0, j, newMatrix);
			det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size - 1));
			degree = -degree;
		}
		//������ ������ �� ������ ���� ��������(�����!)
		for (int i = 0; i < size - 1; i++) {
			delete[] newMatrix[i];
		}
		delete[] newMatrix;
	}

	return det;
}