#ifndef ORIGIN_HPP
#define ORIGIN_HPP

#include <string>

enum class Origin {
	TopLeft,
	TopCentre,
	TopRight,
	CentreLeft,
	Centre,
	CentreRight,
	BottomLeft,
	BottomCentre,
	BottomRight,
	Count
};

extern std::string Origins[];

#endif//ORiGIN_HPP