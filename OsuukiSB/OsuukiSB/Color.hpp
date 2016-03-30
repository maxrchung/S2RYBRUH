#ifndef COLOR_HPP
#define COLOR_HPP

#include <vector>

class Color {
public:
	Color(float r, float g, float b);
	float r;
	float g;
	float b;
	bool operator==(Color c);
};

extern std::vector<Color> Colors;

#endif//COLOR_HPP