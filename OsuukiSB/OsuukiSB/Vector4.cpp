#include "Vector4.hpp"

Vector4::Vector4(Matrix m)
	: x(m[0][0]), y(m[0][1]), z(m[0][2]), w(m[0][3]) {

}

Vector4::Vector4(float x, float y, float z, float w)
	: x(x), y(y), z(z), w(w) {
}