#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector3.hpp"
#include "Vector4.hpp"
#include <vector>

typedef std::vector<std::vector<float>> Table;

class Vector4;
class Matrix {
public:
	explicit Matrix(Vector3 v);
	explicit Matrix(Vector4 v);
	Matrix(int rows, int columns);

	Matrix operator*(const Matrix& rhs);
	std::vector<float> operator[](int row);

	int rows;
	int columns;

	Table table;
};

#endif//MATRIX_HPP