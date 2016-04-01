#include "Color.hpp"

Color::Color(float r, float g, float b) 
	: r(r), g(g), b(b) {
}

Color::Color(float v) 
	: r(v), g(v), b(v) {
}

bool Color::operator==(Color c) {
	return r == c.r && g == c.g && b == c.b;
}