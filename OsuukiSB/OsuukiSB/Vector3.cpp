#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Matrix.hpp"

Vector3::Vector3(float x, float y, float z)
	: x(x), y(y), z(z) {	
}

Vector3::Vector3(Vector2 v)
	: x(v.x), y(v.y), z(0) {

}

Vector3::Vector3(Matrix m)
	: x(m.table[0][0]), y(m.table[1][0]), z(m.table[2][0]) {
	if (m.columns != 1 || m.rows != 3) {
		throw "Cannot turn Matrix into a Vector3; Matrix is not a Vector3";
	}
}

float Vector3::AngleBetween(Vector3 v) {
	if (this->Magnitude() == 0 || v.Magnitude() == 0) {
		throw "Magnitude of a vector is 0";
	}
	else {
		float dotProd = this->Dot(v);
		dotProd /= this->Magnitude() * v.Magnitude();
		return acos(dotProd);
	}
}

Vector3 Vector3::Cross(Vector3 v) {
	return Vector3(y*v.z - z*v.y,
				   z*v.x - x*v.z,
				   x*v.y - y*v.x);
}

float Vector3::Dot(Vector3 v) {
	return x*v.x + y*v.y + z*v.z;
}

float Vector3::Magnitude() {
	return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::Normalize() {
	float len = this->Magnitude();
	return Vector3(x / len, y / len, z / len);
}

Vector3 Vector3::Rotate(float xRad, float yRad, float zRad) {
	float cosx = cos(xRad);
	float cosy = cos(yRad);
	float cosz = cos(zRad);
	float sinx = sin(xRad);
	float siny = sin(yRad);
	float sinz = sin(zRad);
	Matrix rot(3, 3);
	// http://planning.cs.uiuc.edu/node102.html
	rot.table = {
		{ cosx*cosy, cosx*siny*sinz - sinx*cosz, cosx*siny*cosz + sinx*sinz },
		{ sinx*cosy, sinx*siny*sinz + cosx*cosz, sinx*siny*cosz - cosx*sinz },
		{ -siny, cosy*sinz, cosy*cosz },
	};

	return Vector3(rot * (*this));
}

Vector3 Vector3::RotateX(float xRad) {
	return Rotate(xRad, 0, 0);
}

Vector3 Vector3::RotateY(float yRad) {
	return Rotate(0, yRad, 0);
}

Vector3 Vector3::RotateZ(float zRad) {
	return Rotate(0, 0, zRad);
}

Vector3 Vector3::RotateAround(Vector3 v, float rotAmount) {
	v = v.Normalize();

	float r = rotAmount;

	// http://metalbyexample.com/linear-algebra/
	Matrix rot(3, 3);
	rot.table = {
		{ cos(r) + v.x*v.x*(1-cos(r)), v.x*v.y*(1-cos(r)) - v.z*sin(r), v.x*v.z*(1-cos(r)) + v.y*sin(r) },
		{ v.y*v.x*(1-cos(r)) + v.z*sin(r), cos(r) + v.y*v.y*(1 - cos(r)), v.y*v.z*(1-cos(r)) - v.x*sin(r) },
		{ v.z*v.x*(1-cos(r)) - v.y*sin(r), v.z*v.y*(1-cos(r)) + v.x*sin(r), cos(r) + v.z*v.z*(1-cos(r)) },
	};

	return Vector3(rot * (*this));
}

Vector3 Vector3::operator-() {
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator+(Vector3 rhs) {
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 Vector3::operator-(Vector3 rhs) {
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::operator*(float rhs) {
	return Vector3(x * rhs, y * rhs, z * rhs);
}

void Vector3::operator+=(Vector3 rhs) {
	*this = *this + rhs;
}

void Vector3::operator-=(Vector3 rhs) {
	*this = *this - rhs;
}

void Vector3::operator*=(float rhs) {
	*this = *this * rhs;
}