#include "Color.hpp"

Color::Color(double r, double g, double b) 
	: r(r), g(g), b(b) {}

bool Color::operator==(Color c) {
	return r == c.r && g == c.g && b == c.b;
}

std::vector<Color> Colors {
	Color(255, 255, 255),	// White
	Color(97, 214, 255),	// Blue
	Color(249, 254, 54),	// Yellow
	Color(255, 63, 138),	// Pink
	Color(0, 0, 0),			// Black

};