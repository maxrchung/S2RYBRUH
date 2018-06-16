#ifndef EASING_HPP
#define EASING_HPP

#include <string>

enum class Easing {
	Linear,
	EasingOut, // Same as QuadOut - cl8n
	EasingIn, // Same as QuadIn - cl8n
	QuadIn,
	QuadOut,
	QuadInOut,
	CubicIn,
	CubicOut,
	CubicInOut,
	QuartIn,
	QuartOut, // 10
	QuartInOut,
	QuintIn,
	QuintOut,
	QuintInOut,
	SineIn,
	SineOut,
	SineInOut,
	ExpoIn,
	ExpoOut,
	ExpoInOut, // 20
	CircIn,
	CircOut,
	CircInOut,
	ElasticIn,
	ElasticOut,
	ElasticHalfOut,
	ElasticQuarterOut,
	ElasticInOut,
	BackIn,
	BackOut, // 30
	BackInOut,
	BounceIn,
	BounceOut,
	BounceInOut,
	Count
};

static std::string* Easings() {
	static std::string easings[static_cast<int>(Easing::Count)]{
		"Linear",
		"EasingOut",
		"EasingIn",
		"QuadIn",
		"QuadOut",
		"QuadInOut",
		"CubicIn",
		"CubicOut",
		"CubicInOut",
		"QuartIn",
		"QuartOut", // 10
		"QuartInOut",
		"QuintIn",
		"QuintOut",
		"QuintInOut",
		"SineIn",
		"SineOut",
		"SineInOut",
		"ExpoIn",
		"ExpoOut",
		"ExpoInOut", // 20
		"CircIn",
		"CircOut",
		"CircInOut",
		"ElasticIn",
		"ElasticOut",
		"ElasticHalfOut",
		"ElasticQuarterOut",
		"ElasticInOut",
		"BackIn",
		"BackOut", // 30
		"BackInOut",
		"BounceIn",
		"BounceOut",
		"BounceInOut"
	};
	return easings;
}

#endif//EASING_HPP