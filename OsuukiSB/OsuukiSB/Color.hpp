#ifndef COLOR_HPP
#define COLOR_HPP

#include <vector>

class Color {
public:
	Color();
	Color(float r, float g, float b);
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
	bool operator==(Color c);
};

extern std::vector<Color> Colors;

#endif//COLOR_HPP