#include "Vector2.hpp"
#include "math.h"

Vector2::Vector2(double x, double y)
	: x(x), y(y) {}

double Vector2::Magnitude() {
	return sqrt(x * x + y * y);
}

Vector2 Vector2::Normalize() {
	double mag = Magnitude();
	return Vector2(x / mag, y / mag);
}

double Vector2::Dot(Vector2 v) {
	return x * v.x + y * v.y;
}

double Vector2::AngleBetween(Vector2 v) {
	if (this->Magnitude() == 0 || v.Magnitude() == 0) {
		return 0;
	}
	else {
		double dotProd = this->Dot(v);
		dotProd /= this->Magnitude() * v.Magnitude();
		return acos(dotProd);
	}
}

Vector2 Vector2::Project(Vector2 axis) {
	Vector2 projection = Vector2(this->Dot(axis), this->Dot(axis));
	projection /= (axis.x * axis.x) + (axis.y * axis.y);
	projection *= axis;
	return projection;
}

void Vector2::RotateAround(Vector2 origin, double rotation) {
	Vector2 fromMid = *this - origin;
	Vector2 unitVec(1, 0);
	double angleFrom0 = fromMid.AngleBetween(unitVec);
	if (fromMid.y < 0) {
		angleFrom0 *= -1;
	}
	angleFrom0 += rotation;
	Vector2 endMove(cos(angleFrom0), sin(angleFrom0));
	endMove *= fromMid.Magnitude();
	endMove = origin + endMove;

	*this = endMove;
}

Vector2 Vector2::operator-() {
	return Vector2(-x, -y);
}

Vector2 Vector2::operator+(Vector2 v) {
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(Vector2 v) {
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator*(double multiple) {
	return Vector2(x * multiple, y * multiple);
}

Vector2 Vector2::operator*(Vector2 v) {
	return Vector2(x * v.x, y * v.y);
}

Vector2 Vector2::operator/(double division) {
	return Vector2(x / division, y / division);
}

void Vector2::operator+=(Vector2 v) {
	x += v.x;
	y += v.y;
}

void Vector2::operator-=(Vector2 v) {
	x -= v.x;
	y -= v.y;
}

void Vector2::operator*=(double multiple) {
	x *= multiple;
	y *= multiple;
}

void Vector2::operator*=(Vector2 v) {
	x *= v.x;
	y *= v.y;
}

void Vector2::operator/=(double division) {
	x /= division;
	y /= division;
}