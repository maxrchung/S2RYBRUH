#ifndef COLOR_HPP
#define COLOR_HPP

#include <vector>

class Color {
public:
	Color(double r, double g, double b);
	double r;
	double g;
	double b;
	bool operator==(Color c);
};

extern std::vector<Color> Colors;

#endif//COLOR_HPP