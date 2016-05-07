#include "Matrix.hpp"

Matrix::Matrix(int rows, int columns)
	: rows(rows), columns(columns), table(Table(rows, std::vector<float>(columns, 0))) {
}

Matrix::Matrix(Vector3 v)
	: rows(3), columns(1), table(Table(3, std::vector<float>(1, 0))) {
	table[0][0] = v.x;
	table[1][0] = v.y;
	table[2][0] = v.z;
}

Matrix Matrix::operator*(const Matrix& rhs) {
	if (columns != rhs.rows) {
		throw "Cannot multiply matrices; incompatible sizes";
	}

	Matrix mult(rows, rhs.columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < rhs.columns; ++j) {
			float value = 0;
			for (int k = 0; k < columns; ++k) {
				value += table[i][k] * rhs.table[k][j];
			}
			mult.table[i][j] = value;
		}
	}

	return mult;
}