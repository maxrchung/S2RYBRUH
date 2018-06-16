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

static std::string* Origins() {
	static std::string origins[static_cast<int>(Origin::Count)] = {
		"TopLeft",
		"TopCentre",
		"TopRight",
		"CentreLeft",
		"Centre",
		"CentreRight",
		"BottomLeft",
		"BottomCentre",
		"BottomRight"
	};
	return origins;
}

#endif//ORiGIN_HPP