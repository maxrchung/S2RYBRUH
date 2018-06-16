#pragma once

#include "Vector2.hpp"
#include <vector>

class Bezier {
public:
	Bezier(const std::vector<Vector2>& transitions);
	Vector2 findPosition(const float time);
	float length;
private:
	Vector2 binomialPosition(const float time);
	Vector2 deCasteljauPosition(const float time);
	Vector2 reduceCurve(const std::vector<Vector2>& points, const float time);
	float findLength();
	std::vector<Vector2> transitions;
	// Count is the number of points we are looking up the binomial table for
	std::vector<float> getBinomial(const int count);
	static std::vector<std::vector<float>> binomial;
	// How many segments to split for finding length
	static const int lengthSegments = 10;
};