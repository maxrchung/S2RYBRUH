#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
public:
	Vector2(float x, float y);
	float Magnitude();
	Vector2 Normalize();
	float Dot(Vector2 v);
	float AngleBetween(Vector2 v);
	Vector2 Project(Vector2 axis);

	// Rotates around a specified point
	void RotateAround(Vector2 origin, float rotation);

	Vector2 operator-();
	Vector2 operator+(Vector2 v);
	Vector2 operator-(Vector2 v);
	Vector2 operator*(float multiple);
	Vector2 operator*(Vector2 v);
	Vector2 operator/(float division);
	void operator+=(Vector2 v);
	void operator-=(Vector2 v);
	void operator*=(float multiple);
	void operator*=(Vector2 v);
	void operator/=(float division);

	float x;
	float y;
};

#endif//VECTOR2_HPP
