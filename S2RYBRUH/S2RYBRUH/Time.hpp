#pragma once

#include <string>

class Time {
public:
	Time(int value);
	Time();
	Time(std::string format);
	int ms;
	std::string format;
};