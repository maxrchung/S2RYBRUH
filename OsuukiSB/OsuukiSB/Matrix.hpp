#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector3.hpp"
#include <vector>

typedef std::vector<std::vector<float>> Table;

class Matrix {
public:
	Matrix(Vector3 v);
	Matrix(int rows, int columns);
	Matrix operator*(const Matrix& rhs);
	int rows;
	int columns;

	Table table;
};


#endif//MATRIX_HPP