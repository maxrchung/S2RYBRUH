#ifndef VECTOR3_HPP
#define VECTOR3_HPP

// Circular dependency, need to forward declare
class Matrix;
class Vector3 {
public:
	Vector3(Matrix m);
	Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	Vector3 Rotate(float xRad, float yRad, float zRad);
	Vector3 RotateX(float xRad);
	Vector3 RotateY(float yRad);
	Vector3 RotateZ(float zRad);
	Vector3 RotateAround(Vector3 v, float rotAmount);
	Vector3 Normalize();
	float Magnitude();
	float Dot(Vector3 v);
	Vector3 Cross(Vector3 v);

	Vector3 operator-();
	Vector3 operator+(Vector3 rhs);
	Vector3 operator-(Vector3 rhs);
	Vector3 operator*(float rhs);
	void operator+=(Vector3 rhs);
	void operator-=(Vector3 rhs);
	void operator*=(float rhs);

	float x;
	float y;
	float z;
};


#endif//VECTOR3_HPP