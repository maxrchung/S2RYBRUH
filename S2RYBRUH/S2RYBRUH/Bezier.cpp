#include "Bezier.hpp"

std::vector<std::vector<float>> Bezier::binomial = { { 1 } };

Bezier::Bezier(const std::vector<Vector2>& transitions)
	: transitions(transitions) {
	Bezier::length = findLength();
}

Vector2 Bezier::findPosition(const float time) {
	// Anything larger exceeds float numeric limits
	if (transitions.size() <= 33) {
		return binomialPosition(time);
	}
	else {
		return deCasteljauPosition(time);
	}
}

Vector2 Bezier::binomialPosition(const float time) {
	auto position = Vector2::Zero;
	const auto size = transitions.size();
	const auto row = getBinomial(size);
	for (auto i = 0; i < size; i++) {
		const auto point = transitions[i];
		const auto binomial = row[i];
		if (binomial < 1) {
			throw "Binomial value overflow";
		}
		const auto t1 = powf(1 - time, size - i - 1);
		const auto t2 = powf(time, i);
		// Calculate binomial with time first so that we do not run pass float limit
		const auto part = point * (binomial * t1 * t2);
		position += part;
	}
	return position;
}

Vector2 Bezier::deCasteljauPosition(const float time) {
	return reduceCurve(transitions, time);
}

Vector2 Bezier::reduceCurve(const std::vector<Vector2>& points, const float time) {
	if (points.size() == 1) {
		return points.front();
	}
	else {
		auto reduce = std::vector<Vector2>(points.size() - 1);
		for (auto i = 0; i < reduce.size(); i++) {
			reduce[i] = points[i] * (1 - time) + points[i + 1] * time;
		}
		return reduceCurve(reduce, time);
	}
}

std::vector<float> Bezier::getBinomial(const int count) {
	// Add to the table if we have not calculated the row yet
	if (binomial.size() <= count) {
		for (auto i = binomial.size(); i <= count; i++) {
			std::vector<float> row = { 1.0f };
			for (auto j = 1; j < i - 1; j++) {
				auto value = binomial[i - 1][j - 1] + binomial[i - 1][j];
				row.push_back(value);
			}
			row.push_back(1.0f);
			binomial.push_back(row);
		}
	}
	return binomial[count];
}

float Bezier::findLength() {
	auto t = 0.0f;
	auto p1 = findPosition(t);
	auto partSum = 0.0f;
	t += 1.0f / lengthSegments;
	for(auto i = 0; i < lengthSegments; i++){
		const auto p2 = findPosition(t);
		partSum += pow(pow((p2.x - p1.x), 2.0f) + pow((p2.y - p1.y), 2.0f), 0.5f);
		p1 = p2;
		t += 1.0f / lengthSegments;
	}
	return partSum;
}