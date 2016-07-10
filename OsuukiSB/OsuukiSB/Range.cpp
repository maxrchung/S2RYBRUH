#include "Range.hpp"

Range::Range(int start, int end)
	: start(start), end(end) {}

bool Range::Contains(int value) {
	return start <= value && value <= end;
}